
# Components Lògics de Dades
## Esquemes
Unitat administrativa per agrupar un conjunt components.
- **Catàleg**: Grup d’esquemes, un dels quals és anomenat esquema d’informació `information_schema`.
- **Information Schema**: Conjunt de vistes que conté la descripció de totes les dades SQL que pertanyen al catàleg corresponent (Taules, Vistes, Columnes, ...)
- **Servidor**: Pot contindre 0 o + catàlegs.

```ad-info
No es poden CREAR, ELIMINAR, MODIFICAR catàlegs.
```

## Vistes
Permeten independencia lògica de les dades.
No es fica ``ORDER BY`` en la vista. 
Desde la vista es poden modificar les dades de la taula. Si modifiquem una dada i al treïem del "forat" que permet la vista, al tornar a fer un select semblarà que la dada s'ha eliminat.
Per a evitar-ho, hi ha **algunes** vistes que **no** són **actualitzables**:
- [ ] Mirar quines són les vistes que si permeten act.

```SQL
CREATE VIEW _view_name_ [nom_col1, nom_col2, ...] AS  
SELECT _column1_, _column2_, ...  
FROM _table_name_  
WHERE _condition_;
```

