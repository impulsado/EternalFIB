
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
```PostgreSQL
-- Connectar-se
CONNECT TO nom_servidor [AS nom_conexio] [USER username];
SET SCHEMA nom_esquema;

-- Desconnectar-se
DISCONNECT nom_conexio {DEFAULT,CURRENT,ALL};
```

## Vistes
Permeten independència lògica de les dades.
❗No es fica ``ORDER BY`` en la vista. 
Des de la vista es poden modificar les dades de la taula. 
Si modifiquem una dada i la traiem del "forat" que permet la vista, al tornar a fer un select semblarà que la dada s'ha eliminat.
Per a evitar-ho, podem ficar `WITH CHECK OPTION` que no permetrà els `UPDATE` o `INSERT` que post-execució, la dada no estigui "en el forat".
Vista SÍ és actualitzable quan:
- Vista basada en una única taula o una vista si actualitzable. Aquesta no pot tindre `DISTINCT` ni funcions d'agregació (`MAX()`, `COUNT()`, ...).
- El `SELECT` ha d'incloure tots els camps de la taula que tinguin restriccions de `NOT NULL` i no tinguin valor per defecte.
- No poden haver `GROUP BY`.

```PostgreSQL
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

## Privilegis
❗Preval el permís **MENYS** reestrictiu.
SQL defineix 9 tipus de Privilegis:
- **SELECT**: Seleccionar tuples d'una o diverses columnes en taula/vista.
- **INSERT**: Insertar tupla en taula/vista. Es pot seleccionar només algunes columnes i només podrà insertar informació a aquestes columnes.
- **UPDATE**: Actualitzar columna/diverses columnes d'una taula/vista. MOLTES vegades necessitarà el ``SELECT`` per fer referència.
- **DELETE**: Eliminar tupla d'una taula/vista. MOLTES vegades necessitarà el ``SELECT`` per fer referència.
- **REFERENCES**: Permet crear FOREIGN KEYS que fan referència a una taula o columna d'una taula.
- **USAGE**: Permet fer ús de certs objectes de la base de dades, sense atorgar modificació o accedir als continguts. Per exemple esquemes, tipus de dades, ...
- **TRIGGER**: Dret a definir disparadors sobre una taula.
- **EXECUTE**: Permet executar funcions o procediments.
- **ALL**: Tot.

Si volem que un usuari pugi concedir el mateix privilegi a un altre usuari: `WITH GRANT OPTION`.

```PostgreSQL
-- Otorgar
GRANT privilegis ON objectes TO usuaris [WITH GRANT OPTION];

-- Treure
REVOKE [GRANT OPTION FOR] privilegis ON objectes FROM usuaris {CASCADE | RESTRICT};
```

A l'hora d'eliminar podem fer servir dues opcions:
- **CASCADE**: Treu els permisos de tota la cadena de persones, a no ser que aquest permís hagi sigut concedit per una altra via. "Com una cascada d'aigua arrolladora"
- **RESTRICT**: Si hi ha algun permís que depèn d'aquest permís que volem eliminar, no fa res. 

Per entendre `RESTRICT` podem pensar:
Hi ha una sala gran, amb una única entrada, i dins una sala petita, amb una única entrada (que es a través d'aquesta sala gran). Si volen treure la clau de la sala gran no podran perquè si no, perdrien l'accés a la sala petita.