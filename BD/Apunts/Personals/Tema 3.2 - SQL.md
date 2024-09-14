# Introducció
``PRIMARY_KEY`` = Clau que permet identificar de forma única a una tupla (fila) dins una taula.
``FOREIGN_KEY`` = Clau que permet relacionar tuples entre taules diferents.

# Creació Taules
```PostgreSQL
CREATE TABLE <name> (
	table_name [data_type] [constraints] [default_val]
);
```
- **data_types:** INTEGER, FLOAT(precision), CHAR(n), VARCHAR(n), DATE, ...
- **constraints:** 