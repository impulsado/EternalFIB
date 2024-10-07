# Símbols
**AND**: ∧  
**OR**: ∨  
**NOT**: ¬
**NULL**: ω
**full outer join**: ⟗  
**antijoin**: ▷

# Operadors Unàris
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

# Operadors Binaris
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

## Diferència (-)
Actual igual la diferència en "Teoria de Conjunts".
Agafa les tuples (files) que estan en una relació i no en l'altra.
**Exemple**:
$$
\Pi_{name} (\sigma_{main-type='fire'}(\text{Pokemons}) - \Pi_{name} (\sigma_{attack>=100}(\text{Pokemons}))
$$

```ad-important
- Nº attributs en les relacions han de ser les mateixes.
- Tots el i attributs han de ser del mateix domini.
```

## Producte Cartesià (×)
Associa cada tuple de $R_1$ amb cada tupla de $R_2$, sent $R_1 \times R_2$ totes les possibles combinacions de tuples.
Un problema es que alguns atributs poden estar en $R_1$ i $R_2$, fent que es vegi .
**Exemple**: Seleccionar el nom dels entrenadors i pokemons on siguin del mateix tipu
1. Primer creem una taula on estiguin totes les possibles combinacions entre entrenadors i pokemons
$$
\text{TOTES\_COMB} = (\text{trainers} \times \text{pokemons})
$$
2. Ara seleccionem aquells tuples on la especialitat de l'entrenador sigui la mateixa que el tipus principal del pokemon.
$$
\text{NOMES\_ESPECIALITES} = \sigma_{\text{trainers.type} = \text{pokemons.main-type}} (\text{TOTES\_COMB})
$$
3. Seleccionem aquells pokemons que siguin forts.
$$
\text{FORTS} = \sigma_{\text{pokemons.attack>=150} \wedge \text{pokemons.hp>200}} (\text{NOMES\_ESPECIALISTES})
$$
4. Finalment mostrem només el nom de l'entrenador i el nom del pokemon 
$$
\Pi_{\text{trainers.name, pokemons.name}}(FORTS)
$$
# Links
- Relational Algebra Simplified
https://youtube.com/playlist?list=PLdnwl-gHn1DFIbW82OIyO21lke98MAOKk&si=-b8thTrxwJ55ossO
- Llenguatges: Àlgebra Relacional (FIB)
https://learnsql2.fib.upc.edu/moodle/file.php/26/0_Material_general_assignatura/tema3algebra.pdf

