CREATE TYPE treballador_def AS (
	DNI CHAR(8),
	Nom CHAR(30),
	Sou REAL,
	Plus REAL,
	Matricula CHAR(10)
);

CREATE OR REPLACE FUNCTION llistat_treb(dniIni CHAR(8), dniFi CHAR(8))
RETURNS SETOF treballador_def AS 
$$
DECLARE 
	t treballador_def;
	iDni CHAR(8);
	iMatricula CHAR(10);
	missatge VARCHAR(50);

BEGIN
	-- BASE CASE
	SELECT treb.dni INTO iDni FROM treballadors treb WHERE dniIni <= treb.dni AND treb.dni <= dniFi;
	IF (NOT FOUND) THEN 
		RAISE EXCEPTION '';
	END IF;

	-- GENERAL CASE
	FOR iDni IN 
		SELECT treb.dni
		FROM treballadors treb
		WHERE dniIni <= treb.dni AND treb.dni <= dniFi
		ORDER BY treb.dni ASC
	LOOP
		IF (SELECT COUNT (*) FROM lloguers_actius llog2 WHERE llog2.dni = iDni) >= 5 THEN
            FOR iMatricula IN
                SELECT llog.matricula
                FROM lloguers_actius llog
                WHERE llog.dni = iDni
				ORDER BY llog.matricula ASC
            LOOP
					SELECT iDni, treb2.nom, treb2.sou_base, treb2.plus, iMatricula INTO t 
					FROM treballadors treb2 WHERE treb2.dni = iDni;
					RETURN NEXT t;
            END LOOP;
		ELSE
				SELECT iDni, treb2.nom, treb2.sou_base, treb2.plus, NULL INTO t
				FROM treballadors treb2 WHERE treb2.dni = iDni;
				RETURN NEXT t;
        END IF;
	END LOOP;
	
	-- CONTROL ERRORS
	EXCEPTION
		WHEN raise_exception THEN
			SELECT texte INTO missatge FROM missatgesExcepcions WHERE num = 1;
			RAISE EXCEPTION '%', missatge;
		WHEN others THEN
			SELECT texte INTO missatge FROM missatgesExcepcions WHERE num = 2;
			RAISE EXCEPTION '%', missatge;
END;
$$
LANGUAGE plpgsql;