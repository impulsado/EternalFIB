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
Crear restricció `UNIQUE()` de la/les PKs de l'entitat amb `*` i la/les PKs de l'entitat que no hem seleccionat.

## 3. Crear Relacions 1:1
Escollir una entitat i ficar la PK de l'altra entitat com a referencia.
Afegir atributs simples si en te.

## 4. Crear Relacions 1:*
Afegir la PK de la relació `1` com a referencia en la relació `*`.
Afegir atributs simples si en te.
[//]: Recomanació canviar el nom a la foreign key si és relació recursiva.

## 5. Crear Relacions \*:\*
Crear nova relació i afegir totes les PKs i a que fan referencia.
Afegir atributs simples si en te.
