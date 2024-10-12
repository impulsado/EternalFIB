# Símbols
**AND**: ∧  
**OR**: ∨  
**NOT**: ¬
**NULL**: ω
**full outer join**: ⟗  
**antijoin**: ▷

# Operadors Unàris
## Selecció (σ)
Selecciona les tuples (files) que compleixen la condició.
Mostra totes les columnes, com si fos un "SELECT \*"
**Format**: ``R = RELACIO(condicions)``
**Exemple**: ``R = tPokedex(id=2)``

## Projecció (Π)
Només mostra els atributs (columnes) especificades.
❗Elimina tuples repetides.
**Format**: ``R = RELACIÓ[atribut1,...,atributN]``
**Exemple**: ``R = tPokedex[id,name]``
**Exemple2**: ``R = tPokedex(id=2)[name,id]``

## Reanomenament (ρ)
Canviar el nom dels atributs. Útil 
$$
\text{trainers} = \rho_{\text{trainer\_id/id}} (\text{trainers})
$$

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
**Exemple**: Seleccionar el nom dels entrenadors i pokemons on siguin del mateix tipus/especialitat i els pokemons siguin forts (atac major o igual que 150 i vida major de 200)
1. Primer creem una taula on estiguin totes les possibles combinacions entre entrenadors i pokemons
$$
\text{TOTES\_COMB} = (\text{trainers} \times \text{pokemons})
$$
2. Ara seleccionem aquells tuples on la especialitat de l'entrenador sigui la mateixa que el tipus principal del pokemon.
$$
\text{NOMES\_ESPECIALISTES} = \sigma_{\text{trainers.specialty} = \text{pokemons.main-type}} (\text{TOTES\_COMB})
$$
3. Seleccionem aquells pokemons que siguin forts.
$$
\text{FORTS} = \sigma_{\text{pokemons.attac} \geq 150 \wedge \text{pokemons.hp>200}} (\text{NOMES\_ESPECIALISTES})
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

