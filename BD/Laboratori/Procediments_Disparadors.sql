-- Pregunta 1
create or replace function func1()
returns trigger as $$
begin
	if (not exists (select * from empleats2 where ciutat2 = old.ciutat2)) then
		delete from empleats1 where ciutat1 = old.ciutat2;
	end IF;
	return null;
end $$ language plpgsql;


CREATE TRIGGER trig1 AFTER update of ciutat2 or delete ON empleats2
	FOR EACH ROW EXECUTE FUNCTION func1();

-- Pregunta 2
CREATE TYPE prestec AS (
    idBiblioteca CHAR(10),
    idExemplar CHAR(10),
    quantsPrestecs INT
);

CREATE OR REPLACE FUNCTION nou_prestec(idBib CHAR(10), idEx CHAR(10), idUs CHAR(10), instIni INT) 
RETURNS SETOF prestec AS $$
DECLARE
    p prestec;
    msg_error VARCHAR(50);
    quant_exemplars INT;
BEGIN
    -- 1. Insertar en taules les dades
    -- 1.1. "prestecs"
    INSERT INTO prestecs VALUES (idBib, idEx, idUs, instIni, NULL);
    -- 1.2. "exemplarsEnPrestec"
    INSERT INTO exemplarsEnPrestec VALUES (idBib, idEx);

    -- 2. Comprovar si la biblioteca No Admet Més Exemplars
    SELECT COUNT (*) INTO quant_exemplars FROM exemplarsEnPrestec WHERE idBiblioteca = idBib;
    
    IF ((SELECT limitPrestecs FROM biblioteques WHERE idBiblioteca = idBib) < quant_exemplars) THEN
            SELECT texte INTO msg_error FROM missatgesExcepcions WHERE num = 3;
            RAISE EXCEPTION '%', msg_error;
    END IF;

    -- 3. Comprovar saturació de biblioteca
    IF (quant_exemplars > 4) THEN
        IF (NOT EXISTS (SELECT * FROM biblioteques_saturades WHERE idBib = idBiblioteca)) THEN
            INSERT INTO biblioteques_saturades VALUES (idBib);
        END IF;
    END IF;

    -- 4. Retornar llibres que han estat prestats (alguna vegada) amb la quantitat de vegades
    FOR p IN
        SELECT idBib, idExemplarP, COUNT(*)
        FROM prestecs
        WHERE idBibliotecaP = idBib
        GROUP BY idExemplarP
    LOOP
        RETURN NEXT p;
    END LOOP;

    EXCEPTION
        WHEN unique_violation THEN
            SELECT texte INTO msg_error FROM missatgesExcepcions WHERE num = 1;
            RAISE EXCEPTION '%', msg_error;
        WHEN foreign_key_violation THEN
            SELECT texte INTO msg_error FROM missatgesExcepcions WHERE num = 2;
            RAISE EXCEPTION '%', msg_error;
        WHEN raise_exception THEN
            RAISE EXCEPTION '%', sqlerrm;
        WHEN others THEN
            SELECT texte INTO msg_error FROM missatgesExcepcions WHERE num = 4;
            RAISE EXCEPTION '%', msg_error;
END; $$ LANGUAGE plpgsql;