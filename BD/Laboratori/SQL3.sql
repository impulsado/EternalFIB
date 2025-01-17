-- Pregunta 1
select p.nomProf
from professors p
where (p.telefon is not null and p.sou>2500) or (p.telefon is null and not exists (
		select dd.numero
		from despatxos dd
			inner join assignacions aa on dd.numero = aa.numero and dd.modul = aa.modul
		where dd.superficie<20 and p.dni = aa.dni
	)
);

-- Pregunta 2
SELECT p.dni, p.nomProf, a.instantFi AS "Darrer_instant"
FROM professors p
	INNER JOIN assignacions a ON p.dni = a.dni
WHERE (a.instantFi IS NOT NULL) AND NOT EXISTS (
	SELECT *
	FROM despatxos dd
	WHERE dd.numero = a.numero AND dd.modul = a.modul AND dd.superficie<=15
) AND a.instantfi = (
	SELECT a2.instantfi 
	FROM assignacions a2 
	WHERE a2.dni = p.dni AND a2.numero = a.numero AND a2.modul = a.modul
	ORDER BY a2.instantFi DESC 
	LIMIT 1
) AND p.sou <= (
	SELECT AVG(p2.sou)
	FROM professors p2 
)
GROUP BY p.dni, p.nomprof, a.instantfi;

-- Pregunta 3
INSERT INTO despatxos VALUES ('omega','1',15);
INSERT INTO professors VALUES ('123456789', 'pau', '644', 1000);
INSERT INTO assignacions VALUES ('123456789', 'omega', '1', 111, 112);

UPDATE assignacions
SET modul = 'alpha'
WHERE modul = 'omega';

-- Pregunta 4
INSERT INTO professors VALUES ('000','pau','0',100);

INSERT INTO despatxos VALUES 
	('omega','1',15),
	('alpha','1',15);

INSERT INTO assignacions VALUES 
	('000','omega','1',51,53),
	('000','omega','1',52,53),
	('000','alpha','1',52,55);