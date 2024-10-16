
# Components Lògics de Dades
## Esquemes
Unitat administrativa per agrupar un conjunt components.
- **Catàleg**: Grup d’esquemes, un dels quals és anomenat esquema d’informació `information_schema`.
- **Information Schema**: Conjunt de vistes que conté la descripció de totes les dades SQL que pertanyen al catàleg corresponent (Taules, Vistes, Columnes, ...)
- **Servidor**: Pot contindre 0 o + catàlegs.

```ad-info
No es poden CREAR, ELIMINAR, MODIFICAR catàlegs.
```

## Connexions
Associació que es crea entre Client SQL <--> Servidor SQL.
```SQL
-- Connectar-se
CONNECT TO nom_servidor [AS nom_conexio] [USER username];
SET SCHEMA nom_esquema;

-- Desconnectar-se
DISCONNECT nom_conexio {DEFAULT,CURRENT,ALL};
```
## Vistes
Permeten independència lògica de les dades.
❗No es fica ``ORDER BY`` en la vista. 
Des de la vista es poden modificar les dades de la taula. Si modifiquem una dada i la treïem del "forat" que permet la vista, al tornar a fer un select semblarà que la dada s'ha eliminat.
Per a evitar-ho, hi ha **algunes** vistes que **no** són **actualitzables**. 
Vista SÍ és actualitzable quan:
- Vista basada en una única taula o una vista si actualitzable. Aquesta no pot tindre `DISTINCT` ni funcions d'agregació (`MAX()`, `COUNT()`, ...).
- El `SELECT` ha d'incloure tots els camps de la taula que tinguin restriccions de `NOT NULL` i no tinguin valor per defecte.
- No poden haver `GROUP BY`.

```SQL
CREATE VIEW _view_name_ [nom_col1, nom_col2, ...] AS  
SELECT _column1_, _column2_, ...  
FROM _table_name_  
WHERE _condition_
[WITH CHECK OPTIONS];
```

## Esquema d'Informació
Cada catàleg conté un esquema d'informació.
Conté noms i atributs de taules, índexs, restriccions de columna,...
"És un esquema dels esquemes".
Conté vistes accessibles pels usuaris per exemple:
- **SCHEMATA**: Informació  de cada esquema del catàleg
- **DOMAINS**: Informació del domini.
- **TABLES**: Informació sobre les taules.

![[Pasted image 20241008154551.png]]
