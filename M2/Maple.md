# Maple
# Introducció
TODO

# Sobre el programa
- Mode Document: Permet text i funcions interactives juntament amb càlculs.
- Mode Worksheet: Enfocat només a fer càlculs.

## Simbologia General
- ":" Realitzar càlcul sense mostrar resultat.
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

## Funcióv.s. Expressió algebraica
Tot i que siguin molt semblants, maple treballa diferent depenent de com ho haguem definit.
### Funció
Definida amb la notació "->"
```
f := (x, y) -> x^2 + y^2;
f(2, 3);  # Resultat: 13
diff(f(x, y), x);  # Resultat: 2x
```
### Expressió Algebraica
```
g := x^2 + y^2;
subs({x = 2, y = 3}, g);  # Resultat: 13
diff(g,x);  # Resultat: 2x
```
### Error Comú
Quan volem calcular el vector gradient i avaluar en punt, el resultat de derivar se sol guardar en una expressió algebraica per comoditat d'escriptura. <br>
Llavors l'avaluació en aquell punt s'ha de fer tal que:
```
# Definir funció
f := (x, y) -> x^2 + y^2;

# Evaluar derivades parcials
df_dx := diff(f(x,y), x);  # Resultat: 2x  ## Fixe't que ara és una expressió algebraica
df_dy := diff(f(x,y), y);  # Resultat: 2y  ## Fixe't que ara és una expressió algebraica

# Evaluar gradient en determinat Punt.
gradient_en_P := [subs({x=0, y=0}, df_dx), subs({x=0, y=0}, df_dy)];
```


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

## Funcions de diverses variables
### Camp vectors gradients
```
# Preeliminars
restart;
with(VectorCalculus):
with(plots):

# Definir funció
f:=(x,y)->x^2 + y^2;

# Calcular Gradient
grad_f := Gradient(f(x,y),[x,y]);

# Mostrar camp de vectors gradients
fieldplot(grad_f, x=-10..10, y=-10..10);
```

### Corbes de nivell
```
# Preeliminars
restart;
with(plots):

# Definir funció
f:=(x,y)->x^2 + y^2;

# Mostrar corbes de nivell
contourplot(f(x,y), x=-10..10, y=-10..10, contours=[0,1,2,3,4,5,6,7,9,10,15]);
```

# Recursos
## CheatSheet
- https://scipp.ucsc.edu/~haber/webpage/maple_cheatsheet.pdf
- https://bjglez.webs.ull.es/instrucMaple.pdf

## Vídeos
### Maple general
https://youtu.be/zIjrbZIOdUY?si=dokJDppfUEcpxytE

### Solucions pas a pas
https://youtu.be/qPJ_6UT9lvY?si=N7I6DsX48cJ06bIJ