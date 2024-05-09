# Maple
# Introducció
TODO

# Sobre el programa
- Mode Document: Permet text i funcions interactives juntament amb càlculs.
- Mode Worksheet: Enfocat només a fer càlculs.

## Simbologia General
- ":" Realitzar càlcul sense mostrar resultat
- ";" Realitzar càlcul i mostrar-lo. Separador d'instruccions a l'hora de programar.
- ":=" Assignar valor. Exemple "p:=sqrt(2)" assigna a la variable "p" l'arrel quadrada de 2. No el valor númeric.
- "p:='p'" Dessasignar valor. "p" torna a ser una variable.
- "f:=x->2x" Construïr expressio.
- "%" Guarda valor de l'última operació realitzada.

## Simbologia Matemàtica
- "expand()" Desenvolupar expressió. Per defecte no ho fa.
- "evalf(p)" Calcular avaluació númerica d'una expressió.
- "evalf[100](pi)" Determinar nombre de dígits de l'avaluació.
- "subs(x=valor,expressio)" Substitueix el valor de x en l'expressió. No el calcula si no fas evalf().
- "solve(expressio,x)" Resol expressió respecte x.
- "solve({x+2*y=1,x-y=3},{x,y});" Resol sistema d'equacions.

# Aplicacións a M2 
## Equacions i inequacions amb nombres reals.
```
expr := (x - 1)/(x + 1) <= (x + 1)/(x - 1);
                             x - 1    x + 1
                     expr := ----- <= -----
                             x + 1    x - 1

solve(expr, x);
      RealRange(Open(-1), 0), RealRange(Open(1), infinity)
```

## Successions de nombres reals.
```
f := 5*(n + 1)^(n + 1)/((3*n^2 + 1)*n^(n - 1));
                                   (n + 1)  
                          5 (n + 1)         
                    f := -------------------
                         /   2    \  (n - 1)
                         \3 n  + 1/ n       

limit(f, n = infinity);
                            5       
                            - exp(1)
                            3       
```

# Recursos
## CheatSheet
https://scipp.ucsc.edu/~haber/webpage/maple_cheatsheet.pdf
https://bjglez.webs.ull.es/instrucMaple.pdf

## Vídeos
### Maple general
https://youtu.be/zIjrbZIOdUY?si=dokJDppfUEcpxytE

### Solucions pas a pas
https://youtu.be/qPJ_6UT9lvY?si=N7I6DsX48cJ06bIJ