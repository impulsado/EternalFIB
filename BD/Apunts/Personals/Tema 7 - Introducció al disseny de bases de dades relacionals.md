# Algoritme
## 1. Crear Entitats Regulars
Ficar PK, Atributs.
Si és una generalització, la PK serà la de la superclasse i farà referencia a aquesta.
[//]: Recomanació canviar el nom a la PK "heredada"

## 2. Crear Entitats Associatives (Linies discontinues)
Ficar totes les PK de les entitats que associa i atributs.
Seleccionar l'entitat amb `*` i una de les `0..1` i seleccionar les seves PK per formar la PK de la entitat.
Ficar a on referencia cada PK.
La/les PKs de la taula que **NO** hem seleccionat hem d'especificar que `NOT NULL`
Crear reestricció `UNIQUE()` de la/les 