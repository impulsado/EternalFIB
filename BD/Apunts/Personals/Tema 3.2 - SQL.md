# Introducció
``PRIMARY_KEY`` = Clau que permet identificar de forma única a una tupla (fila) dins una taula.
``FOREIGN_KEY`` = Clau que permet relacionar tuples entre taules diferents.

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
Tots dos codis són equivalents
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
CREATE TABLE pokedex (
	pok INTEGER PRIMARY KEY,
	pokemon_name CHAR(255) UNIQUE,
	pokemon_type CHAR(255),
	pokemon_hp INTEGER DEFAULT 100 CHECK (pokemon_hp>0),
	pokemon_attack INTEGER,
	
);
```