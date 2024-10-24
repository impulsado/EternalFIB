# Algoritme
## 1. Crear Entitats Regulars
Ficar PK, Atributs.
Si és una generalització, la PK serà la de la superclasse i farà referencia a aquesta.
[//]: Recomanació canviar el nom a la PK "heredada"

## 2. Crear Entitats Associatives (Linies discontinues)

Afegir atributs simples si en te.

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

## 6. Crear Associacions N-aries
### 6.1 Associació \*:\*:1
Ficar totes les PKs i on referencien.
Seleccionar les PKs de les relacions `*` i crear la PK de la associació.
La/Les PKs de la relació `1` hem d'especificar que son `NOT NULL`.
### 6.2 Associació 1:1:*
Ficar totes les PKs i on referencien.
Seleccionar l'entitat amb `*` i una de les `0..1` i seleccionar les seves PK per formar la PK de la entitat.
La/les PKs de la taula que **NO** hem seleccionat hem d'especificar que han de ser `NOT NULL`.
Crear restricció `UNIQUE()` de la/les PKs de l'entitat amb `*` i la/les PKs de l'entitat que no hem seleccionat.