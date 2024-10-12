# Operadors Unaris
## Selecció (σ)
Selecciona les tuples (files) que compleixen la condició.
Mostra totes les columnes, com si fos un "SELECT \*"
**Format**: ``R = RELACIO(condicions)``
**Exemple**: ``R = tPokedex(id=2)``
![[Pasted image 20241012102745.png]]
## Projecció (Π)
Només mostra els atributs (columnes) especificades.
❗Elimina tuples repetides.
**Format**: ``R = RELACIÓ[atribut1,...,atributN]``
**Exemple**: ``R = tPokedex[id,name]``
**Exemple2**: ``R = tPokedex(id=2)[name,id]``
![[Pasted image 20241012102756.png]]
## Reanomenament (ρ)
Canviar el nom d'una relació o dels seus atributs.
**Format**: `R = RELACIO{atribu1->atributA, atribut2->atributB}`
**Exemple**: ``R = tTrainers{id -> trainer_id}``

# Operadors Binaris

```ad-warning
**Relacions Compatibles** 
Les relacions han de tenir el mateix esquema: 
- Mateixa quantitat d'atributs.
- Els atributs corresponents han de coincidir en Nom, Tipus de dada i Ordre.
```
## Unió (∪)
Totes les tuples de les relacions.
Elimina tuples repetides (Si estan en la intersecció per exemple).
❗Les relacions han de ser compatibles.
**Format**: ``R = RELACIO1 ∪ RELACIO2``
**Exemple**: `R = tPokemonsGen1 ∪ tPokemonsGen2`
![[Pasted image 20241012102807.png]]
## Intersecció (∩)
Tuples que tenen en comú les relacions.
❗Les relacions han de ser compatibles.
**Format**: `R = RELACIO1 ∩ RELACIO2`
**Exemple**: ``R = tPokemonsGen1 ∩ tPokemonsLegend`` 
![[Pasted image 20241012102813.png]]
## Diferència (-)
Agafa les tuples que estan en una relació i no en l'altra.
❗Les relacions han de ser compatibles.
**Format**: `R = RELACIO1 - RELACIO2`
**Exemple**: `R = (tPokedex(attack>=100)) - (tPokedex(hp<=50))`
![[Pasted image 20241012102820.png]]
## Producte Cartesià (×)
Associa cada tuple de $R_1$ amb cada tupla de $R_2$, sent $R_1 \times R_2$ totes les possibles combinacions de tuples.
Si $R_1$ i $R_2$ tenen un atribut `i` amb el mateix nom, a la relació resultat pot haver ambiguetat.
[//]: Si obs. que pot arribar a passar, haurem de fer prèviament un reanomenament.
❗NO cal que siguin compatibles.
**Format**: ``R = RELACIO1 × RELACIO2``
**Exemple**: ``R = tTrainers × tPokedex``
![[Pasted image 20241012102832.png]]
## Combinació (Ģ)
Relació que combina relacions complint una condició donada.
**Format**: `R = RELACIO1[condicions]RELACIO2`
**Exemple**: `R = tTrainers[name=trainer_name]tTournamentWinners`
![[Pasted image 20241012103903.png]]
# Exemple 
Seleccionar el nom dels entrenadors i pokemons on siguin del mateix tipus/especialitat i els pokemons siguin forts (atac major o igual que 150 i vida major de 200).
1. Primer agafem totes les possibles combinacions.
`TOTS = tTrainers × tPokedex`
2- 


# Links
- Relational Algebra Simplified
https://youtube.com/playlist?list=PLdnwl-gHn1DFIbW82OIyO21lke98MAOKk&si=-b8thTrxwJ55ossO
- Llenguatges: Àlgebra Relacional (FIB)
https://learnsql2.fib.upc.edu/moodle/file.php/26/0_Material_general_assignatura/tema3algebra.pdf

