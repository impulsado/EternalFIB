# Algoritme
## 1. Crear Entitats Regulars
Ficar PK, Atributs.
Si és una generalització, la PK serà la de la superclasse i farà referència a aquesta.
[//]: Recomanació canviar el nom a la PK "heretada"

## 2. Crear Entitats Associatives (Linies discontinues)
Mirar apartat `6.1` o `6.2` per mirar quines PKs seleccionar.
Afegir atributs simples si en te.

## 3. Crear Relacions 1:1
Escollir una entitat i ficar la PK de l'altra entitat com a referència.
La FK ha de ser `UNIQUE`. Això serveix per limitar que es converteixi en `*`.
Afegir atributs simples si en te.

## 4. Crear Relacions 1:*
Afegir la PK de la relació `1` com a referència en la relació `*`.
Afegir atributs simples si en te.
❗Si és `1` s'ha de ficar `NOT NULL`. Si és `0..1` no fa falta.
[//]: Recomanació canviar el nom a la foreign key si és relació recursiva.

## 5. Crear Relacions \*:\*
Crear nova relació i afegir totes les PKs i a que fan referència.
Afegir atributs simples si en te.

## 6. Crear Associacions N-aries
### 6.1 Associació \*:\*:1
Ficar totes les PKs i on fan referència.
Seleccionar les PKs de les relacions `*` i crear la PK de la associació.
La/Les PKs de la relació `1` hem d'especificar que son `NOT NULL`.
### 6.2 Associació 1:1:*
Ficar totes les PKs i on fan referència.
Seleccionar l'entitat amb `*` i una de les `0..1` i seleccionar les seves PK per formar la PK de la entitat.
La/les PKs de la taula que **NO** hem seleccionat hem d'especificar que son `NOT NULL`.
Crear restricció `UNIQUE()` de la/les PKs de l'entitat amb `*` i la/les PKs de l'entitat que no hem seleccionat.