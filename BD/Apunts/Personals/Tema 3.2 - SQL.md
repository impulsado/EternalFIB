# Introducció
``PRIMARY_KEY`` = Clau que permet identificar de forma única a una tupla (fila) dins una taula.
``FOREIGN_KEY`` = Clau que permet relacionar tuples entre taules diferents.

## CHAR(n) VS VARCHAR(n)
CHAR(n) reserves mida fixa. Si no ocupes tot, continua reservat.
VARCHAR(n) reserves mida dinàmica amb màxim `n`. Si només ocupes la meitat, es reserva la meitat.

# Creació Taules
```PostgreSQL
CREATE TABLE <table_name> (
	col_name [data_type] [col_constraints] [default_val],
	[...],
	table_constraints
);
```
- **data_types:** INTEGER, FLOAT(precision), CHAR(n), VARCHAR(n), DATE, ...
- **col_constraints:** 

| Reestriccions                              | Explicació                                                   |
| ------------------------------------------ | ------------------------------------------------------------ |
| UNIQUE                                     | La col. no pot tindre valors repetits                        |
| PRIMARY KEY                                | La col. és la primary key de les tuples                      |
| REFERENCES <ref_table_name> (ref_col_name) | La col. és foreign key a la columna de la taula especificada |
| CHECK (conditions)                         | Col. ha de complir les condicions                            |
| NOT NULL                                   | Ha de tindre algun valor                                     |
- **table_constraints:**

| Reestriccions                              | Explicació                                         |
| ------------------------------------------ | -------------------------------------------------- |
| UNIQUE                                     | Les cols. especificades han de tindre valors únics |
| PRIMARY KEY                                | Les cols. especificades son les primary keys       |
| REFERENCES <ref_table_name> (ref_col_name) | Les cols. especificades son les foreign keys       |
| CHECK (conditions)                         | La taula ha de complir les condicions              |

## Exemples
### col_constraint VS table_constraint
Tots dos codis són equivalents:
```PostgreSQL
CREATE TABLE t1 (
	id INTEGER UNIQUE,
	name VARCHAR(255) UNIQUE
);
```

```PostgreSQL
CREATE TABLE t1 (
	id INTEGER,
	name VARCHAR(255),
	UNIQUE (id, name)
);
```

### Complet
```PostgreSQL
CREATE TABLE tPokedex (
	pkmn_id SERIAL PRIMARY KEY,
	pkmn_name VARCHAR(255) UNIQUE NOT NULL,
	pkmn_hp INTEGER DEFAULT 100 CHECK (pkmn_hp>0),
	pkmn_attack INTEGER,
	FOREIGN KEY pkmn_type REFERENCES tTypes(type_name),
	CHECK (pkmn_hp>pkmn_attack)
);
```

## Inserció de Files
Si no es fiquen les columnes on van les dades que s'han d'introduir, s'han de ficar en ordre tal com està definida la taula. Altrament, s'ha de respectar l'ordre de menció del nom de les taules.
En el futur podrem veure que el valor que s'introdueix pot vindre donat de subconsultes.

### Exemples
```PostgreSQL
INSERT INTO tPokedex(pkmn_id, pkmn_name, pkmn_hp, pkmn_attack)
VALUES (1, Bulbasur, 49, 45),
VALUES (2, Ivysaur, 62, 60);
```

## Esborrat de Files
```PostgreSQL
DELETE FROM table_name
WHERE <conditions>;
```

### Exemples
```PostgreSQL
DELETE FROM tPokedex
WHERE pkmn_hp=30 AND pkmn_attack<=30;
```

## Modificació de Files
És modifiquen les columnes que estiguin especificades en el **SET** que compleixin la condició **WHERE** de la taula **UPDATE**.
```PostgreSQL
UPDATE tName
SET col_name = {expression/NULL}, col_name = {expression/NULL}, ...
WHERE <conditions>;
```

### Exemples
```PostgreSQL
UPDATE tPokedex
SET pkmn_hp = pkmn_hp+50, pkmn_attack = 100
WHERE pkmn_id = 100;
```

## Consultes sobre una Taula
### Format Bàsic
#### Exemple
```PostgreSQL
SELECT *
FROM tPokedex
WHERE 
	NOT(pkmn_id=1) 
	AND(pkmn_name IN('Gengar','Mimikyu') OR pokm_name LIKE 'C%')
	AND pkmn_attack IS NOT NULL
	AND pkmn_hp BETWEEN 100 AND 200;
```

### Ordenació
Si no s'especifica ``DESC`` s'entén que és `ASC`.
#### Exemple
En aquest cas, s'ordena per menor attack (mínim 100) i en cas d'empat, s'ordena per nom ascendent.
```PostgreSQL
SELECT pkmn_id, pkmn_name, pkmn_attack
FROM tPokedex
WHERE pkmn_attack>=100
ORDER BY pkmn_attack DESC, pkmn_name
```

### Agregació
- **COUNT:**
	- **COUNT(\*):**  Número de files que compleixen condició del ``WHERE``.
	- **COUNT(DISTINCT col_name):** Número de valors diferents de la columna (sense comptar NULL).
	- **COUNT(col_name):** Número de valors de la columna que compleixen. Sense comptar NULL.

#### Exemple
```PostgreSQL
SELECT 
```