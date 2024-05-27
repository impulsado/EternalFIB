# Maple
# Introducció
Maple és un programa relacionat amb les matemàtiques que podem fer servir per a fer més sencill l'aprenentage i resolució de problemes.<br>

❗Per ser estudiant de l'UPC disposses del **Maple GRATUÏT**❗ <br>
[MÉS INFORMACIÓ](https://serveistic.upc.edu/ca/distsoft/el-servei/programari-per-a-estudiantsi-professors#autotoc-item-autotoc-9)

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
- "evalf\[100](pi)" Determinar nombre de dígits de l'avaluació.
- "subs(x=valor,expressio)" Substitueix el valor de x en l'expressió. No el calcula si no fas evalf().
- "solve(expressio,x)" Resol expressió respecte x.
- "solve({x+2*y=1,x-y=3},{x,y});" Resol sistema d'equacions.

## Funció v.s. Expressió algebraica
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
# Definir expressió
expr := (x - 1)/(x + 1) <= (x + 1)/(x - 1);

# Saber els valors de x que compleixen
solve(expr, x);
```

## Successions de nombres reals.
### Successions
```
# Definir successió
a := n -> if n=1 then 3; else sqrt(5 + a(n-1)); end if;

# Veure valors per determinar [Creixent/Decreixent]
seq(evalf(a(n)), n=1..10);

# Calcular límit
valor_limit := solve(L = sqrt(5 + L), L);
```

### Límits
NOTA: Aixìo també és pot fer amb els símbols de la secció lateral esquerra.
```
# Definir expressió
f := 5*(n + 1)^(n + 1)/((3*n^2 + 1)*n^(n - 1));

# Calcular límit
limit(f, n = infinity);
```

## Zero de funcions
Escribim ``maxiterations = 100`` perquè per defecte amb `output = information` son 10 iteracions i podria ser que no fossin suficients.
Si volem veure el resultat comodament s'ha de treure el parametre de ``output``.
```
# Preeliminars
restart;
with(Student[NumericalAnalysis]):

# Definir expressió
f := 2*x^4 - 9.41*x^3 + 14.44*x^2 - 19.77*x + 21.51;

# Mètodes
## Bisecció
Bisection(f, x = [1, 2], tolerance = 10^(-3), output = information, maxiterations = 100);
## Secant
Secant(f, x = [1, 2], tolerance = 10^(-3), output = information, maxiterations = 100);
## Newton/Tangent
Newton(f, x = 4.004, tolerance = 10^(-5), output = information, maxiterations = 100)
```

## Fórmula de Taylor
```
# Preeliminars
restart;
with(Student[NumericalAnalysis]):

# Definir expressió
f := 21/5*exp(x + 5);

# Calulcar polinomi de Taylor
pol_f := TaylorPolynomial(f, x = 1, order = 3);

# Calcular Residu de Lagrange
res_f := TaylorPolynomial(f, x = 1, order = 3, errorboundvar = 'ξ')  # La lletra pot ser qualsevol.

# Mostrar les funcions conjuntes
plot([f, pol_f], x = 1 .. 3);
```

## Integració
### Mètodes
Per calcular el valor numèric d'una integral amb algun mètode no hi ha una comanda explícita. S'ha d'anar a:
Tools -> Tutors -> "Calculus - Single Variable" -> "Riemann Sums..."
I escriure la nostra integral amb el seu interval i seleccionar el mètode.

### Fòrmula de l'error
Per a fer-ho més senzill faré servir `g` per a referirme al grau:
```c++
if (Trapezzis) g = 2; else g = 4;
```

```
# Preeliminars
restart;
with(Optimization):

# Definir variables
f := exp(3*x - 1); 
a := 1/4; b := 13/4; g := 2;
val_error := 10^(-9);

# Calcular derivada i el seu màxim en l'interval
f_deri := diff(f,[x$g]);
max_value := maximize(f_deri, x = a..b);

# Calcular número iteracions
iteracions := solve((b-a)^(g+1)/(12*n^2)*max_value < val_error, n);
evalf(iteracions);
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