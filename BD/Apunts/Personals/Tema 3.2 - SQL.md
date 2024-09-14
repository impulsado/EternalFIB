# Introducció
``PRIMARY_KEY`` = Clau que permet identificar de forma única a una tupla (fila) dins una taula.
``FOREIGN_KEY`` = Clau que permet relacionar tuples entre taules diferents.

# Creació Taules
```PostgreSQL
CREATE TABLE <table_name> (
	col_name [data_type] [constraints] [default_val]
);
```
- **data_types:** INTEGER, FLOAT(precision), CHAR(n), VARCHAR(n), DATE, ...
- **constraints:** 
| UNIQUE | La col. no pot tindre valors repetits |
| PRIMARY KEY | La col. es la primary key de les tuples |
| REFERENCES <ref_table_name> (ref_col_name) | La col. es foreign key a la columna de la taula especificada |
| CHECK 