-- Pregunta 1
SELECT d.modul AS MODUL, SUM(a.instantFi-a.instantInici) AS SUMAA
FROM despatxos d NATURAL INNER JOIN assignacions a
WHERE a.instantFi IS NOT NULL
GROUP BY d.modul
ORDER BY d.modul ASC;

-- Pregunta 2
SELECT DISTINCT d.num_dpt, d.nom_dpt, d.ciutat_dpt
FROM departaments d 
	NATURAL INNER JOIN empleats e
WHERE NOT EXISTS (
	SELECT 1
	FROM empleats e2
	WHERE e2.num_dpt = e.num_dpt and e2.num_proj != e.num_proj
);

-- Pregunta 3
A = professors(sou<=2500)
B = despatxos(superficie<20)
C = A*assignacions
D = C*B
E = D[nomProf]
F = professors[nomProf]
G = F-E
H = professors(sou>2500)
I = H[nomProf]
R = I_u_G

-- Pregunta 4
CREATE TABLE presentacioTFG (
	idEstudiant CHAR(100) PRIMARY KEY,
	titolTFG CHAR(100) NOT NULL,
	dniDirector char(50) NOT NULL,
	dniPresident char(50) NOT NULL,
	dniVocal char(50) NOT NULL,
	instantPresentacio INT NOT NULL,
	nota INT CHECK(10>=nota AND nota>=0) DEFAULT NULL,
	UNIQUE (titolTFG, dniDirector),
	FOREIGN KEY (dniDirector) REFERENCES professors (dni),
	FOREIGN KEY (dniPresident) REFERENCES professors (dni),
	FOREIGN KEY (dniVocal) REFERENCES professors (dni),
	CHECK (dniDirector != dniPresident AND dniDirector != dniVocal),
	CHECK (dniPresident != dniVocal)
);

-- Pregunta 5
INSERT INTO COST_CIUTAT (
SELECT DISTINCT d.ciutat_dpt, 0
FROM departaments d
WHERE d.ciutat_dpt NOT IN (
	SELECT d2.ciutat_dpt
	FROM departaments d2 NATURAL INNER JOIN empleats e2
)
);