# Àlgebra Relacional
## Símbols
**AND**: ∧  
**OR**: ∨  
**NOT**: ¬
**NULL**: ω
**full outer join**: ⟗  
**antijoin**: ▷

## Select (σ)
Selecciona les tuples (files) que compleixen la condició.
Mostra totes les columnes, com si fos un "SELECT \*"
**Format**: ``σ_<select_cond> (Relation)``
**Exemple**: ``σ_id=2 (Pokemons)``

## Project (Π)
Només mostra els atributs (columnes) especificades.
Elimina tuples repetides.
**Format**: ``Π_<attribute1,attriubte2,...> (Relation)``
**Exemple**: ``Π_name (Pokemons)``
**Exemple2**: ``Π_name(σ_type='fire' (Pokemons))``

## Unió (∪)
Actua com la unió en "Teoria de Conjunts".
Elimina tuples repetides (Si estan en la intersecció per exemple).
Recorda que qualsevol relació es un conjunt (set).
**Format**: `Π_<attribute1,attriubte2,...> (Relation_1) ∪ Π_<attribute1,attriubte2,...> (Relation_2)`
**Exemple**: 
$$
\Pi_{\text{name}} \left( \sigma_{\text{main-type} = 'fire' \land \text{attack} < 100} (\text{Pokemons}) \right) \cup \Pi_{\text{name}} \left( \sigma_{\text{sec-type} = 'bug' \lor \text{type} = 'steel'} (\text{Pokemons}) \right)
$$
```ad-important
- Nº attributs en les relacions han de ser les mateixes.
- Tots el i attributs han de ser del mateix domini.
```


# Links
- Relational Algebra Simplified
https://youtube.com/playlist?list=PLdnwl-gHn1DFIbW82OIyO21lke98MAOKk&si=-b8thTrxwJ55ossO
- Llenguatges: Àlgebra Relacional (FIB)
https://learnsql2.fib.upc.edu/moodle/file.php/26/0_Material_general_assignatura/tema3algebra.pdf

