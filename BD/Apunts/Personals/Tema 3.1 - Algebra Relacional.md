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
**Exemple2**: ``Π_name(σ_type=fire (Pokemons))``