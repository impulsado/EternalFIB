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

# Inserció de Files
Si no es fiquen les columnes on van les dades que s'han d'introduir, s'han de ficar en ordre tal com està definida la taula. Altrament, s'ha de respectar l'ordre de menció del nom de les taules.
En el futur podrem veure que el valor que s'introdueix pot vindre donat de subconsultes.

## Exemples
```PostgreSQL
INSERT INTO tPokedex(pkmn_id, pkmn_name, pkmn_hp, pkmn_attack)
VALUES (1, Bulbasur, 49, 45),
VALUES (2, Ivysaur, 62, 60);
```

# Esborrat de Files
```PostgreSQL
DELETE FROM table_name
WHERE <conditions>;
```

## Exemples
```PostgreSQL
DELETE FROM tPokedex
WHERE pkmn_hp=30 AND pkmn_attack<=30;
```

# Modificació de Files
És modifiquen les columnes que estiguin especificades en el **SET** que compleixin la condició **WHERE** de la taula **UPDATE**.
```PostgreSQL
UPDATE tName
SET col_name = {expression/NULL}, col_name = {expression/NULL}, ...
WHERE <conditions>;
```

## Exemples
```PostgreSQL
UPDATE tPokedex
SET pkmn_hp = pkmn_hp+50, pkmn_attack = 100
WHERE pkmn_id = 100;
```

# Consultes sobre una Taula
## Format Bàsic
### Exemple
```PostgreSQL
SELECT *
FROM tPokedex
WHERE 
	NOT(pkmn_id=1) 
	AND(pkmn_name IN('Gengar','Mimikyu') OR pokm_name LIKE 'C%')
	AND pkmn_attack IS NOT NULL
	AND pkmn_hp BETWEEN 100 AND 200;
```

## Ordenació
Si no s'especifica ``DESC`` s'entén que és `ASC`.
### Exemple
En aquest cas, s'ordena per menor attack (mínim 100) i en cas d'empat, s'ordena per nom ascendent.
```PostgreSQL
SELECT pkmn_id, pkmn_name, pkmn_attack
FROM tPokedex
WHERE pkmn_attack>=100
ORDER BY pkmn_attack DESC, pkmn_name
```

## Agregació
- **COUNT:**
	- **COUNT(\*):**  Número de files que compleixen condició del ``WHERE``. Compta les NULL.
	- **COUNT(DISTINCT col_name):** Número de valors diferents de la columna (sense comptar NULL).
	- **COUNT(col_name):** Número de valors de la columna que compleixen. Sense comptar NULL.

La diferencia entre ``COUNT(col_name)`` i ``COUNT(\*)`` és per quan ``col_name`` pot ser NULL. 

### Exemple
```PostgreSQL
SELECT 
	COUNT(DISTINCT pkm_id) AS quant_total,
	AVG(pkmn_hp) AS avg_vida,
	SUM(pkmn_attack) AS total_attack
FROM tPokedex
```

## Agrupació de Files
Agrupar resultats depenent d'una columna.
### Exemple
```PostgreSQL
SELECT pkmn_type, COUNT(*) AS quant_pkmns
FROM tPokedex
GROUP BY pkmn_type
```

I això mostraria algo com:

| pkmn_type | quant_pkmns |
| --------- | ----------- |
| water     | 2           |
| fire      | 10          |


# Consultes sobre diverses Taules
## Diferencia "WHERE" i "HAVING"
- `WHERE`: Filtrar **abans** d'agrupar-se.
- `HAVING`: Filtrar **després** d'agrupar-se. Útil amb `SUM()`, `COUNT()`,...

## Unió
Resultat és la unió de dues sentències `SELECT`.

```ad-important
El resultat de totes les consultes han de tindre MATEIX # DE COLS i han de ser del MATEIX TIPUS.
```

### Exemple
```postgreSQL
SELECT pkmn_name
FROM pokemons_gen1
UNION
SELECT pkmn_name
FROM pokemons_gen2;
```

## Diferència
Dues formes diferents de fer-ho: 
- `NOT IN`: Compara els valors d'una columna de la consulta principal amb els valors de la sub-consulta. **! Compte per què amb NULL falla !**
- `NOT EXISTS`: Verifica si una condició és verdadera o falsa per cada fila.

### Exemple `NOT IN`
Mostrar Pokèmons que no són llegendaris:
```postgreSQL
SELECT pa.name
FROM pokemons_all pa
WHERE pa.id NOT IN (
	SELECT pl.id
	FROM pokemons_legendary pl
);
```

### Exemple `NOT EXISTS`
[//]: `SELECT 1` només fa que retorni 1, per la sub-consulta. NO és més eficient.

```postgreSQL
SELECT pa.name
FROM pokemons_all pa
WHERE pa.id NOT EXISTS (
	SELECT 1
	FROM pokemon_legendary pl
	WHERE pa.id = pl.id 
);
```

# Subconsultes en `DELETE`, `UPDATE` i `SELECT`
## Exemple `DELETE`
Eliminar de la taula `pokemons` els que no siguin llegendaris:
```postgreSQL
DELETE FROM pokemons p
WHERE NOT EXISTS (
	SELECT 1
	FROM pokemons_legendary pl
	WHERE p.id = pl.id
);
```

## Exemple `UPDATE`
Pujar 50 punts d'atac aquells que tinguin més vida que la vida mitjana dels llegendaris:
```postgreSQL
UPDATE pokemons p
SET p.attk = p.attk + 50
WHERE p.hp >= (
	SELECT AVG(pl.hp)
	FROM pokemons_legendary pl
);
```

# Subconsultes en `INSERT`
Afegir a la taula de pokemons normal els pokemons llegendaris que tinguin 2 o més tipus.
[//]: Per fer més fàcil la consulta, el tipus que reben aquest nous pokemons és "Multi-tipo".

```postgreSQL
INSERT INTO pokemons (id, name, type)
SELECT pl.id, pl.name, 'Multi-tipo'
FROM pokemons_legendary pl 
	INNER JOIN pokemons_tipos pt ON pl.id = pt.id
GROUP BY pl.id, pl.name
HAVING COUNT(pt.id) >= 2;
```

```ad-important
Recorda que si fas un `GROUP BY, totes les columnes del `SELECT` 
```
