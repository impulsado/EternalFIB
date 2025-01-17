-- Pregunta 1
CREATE OR REPLACE FUNCTION check_empleat()
RETURNS trigger AS 
$$
DECLARE
	missatge VARCHAR(100);

BEGIN
	IF (OLD.nempl = 123) THEN 
		SELECT texte INTO missatge FROM missatgesExcepcions WHERE num = 1;	
		RAISE EXCEPTION '%', missatge;
	END IF;
	
	IF (TG_OP = 'DELETE') then RETURN OLD;
	ELSE RETURN NEW;
	END IF;
end $$ LANGUAGE plpgsql;

CREATE TRIGGER trig1 BEFORE UPDATE OF nempl OR DELETE ON empleats
	FOR EACH ROW EXECUTE FUNCTION check_empleat();

-- Pregunta 2
CREATE OR REPLACE FUNCTION check_dia()
RETURNS trigger AS $$
DECLARE
	missatge VARCHAR(100);

BEGIN
	IF (SELECT dia FROM dia) = 'dijous' THEN
		SELECT texte INTO missatge FROM missatgesExcepcions WHERE num = 1;	
		RAISE EXCEPTION '%', missatge;
	END IF;
	RETURN OLD;
END
$$ LANGUAGE plpgsql;

CREATE TRIGGER trig2 BEFORE DELETE ON empleats
	FOR EACH STATEMENT EXECUTE FUNCTION check_dia();

-- Pregunta 3
CREATE OR REPLACE FUNCTION act_import() RETURNS TRIGGER AS $$
DECLARE
	preu_prod INT;

BEGIN 
	SELECT preu INTO preu_prod FROM productes WHERE idProducte = NEW.idProducte;

	UPDATE comandes 
	SET import = import + preu_prod*NEW.quantitat
	WHERE numComanda = NEW.numComanda;

	RETURN NULL; -- No importa perque es AFTER
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trig3 AFTER INSERT ON liniesComandes
	FOR EACH ROW EXECUTE FUNCTION act_import();