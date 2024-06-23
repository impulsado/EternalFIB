#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

class Estudiant {

  // Tipus de mòdul: dades
  // Descripció del tipus: conté el DNI d'un estudiant, 
  // que és un enter positiu, i pot tenir nota, que seria un double 
  // Les notes vàlides són les de l'interval 0..nota_maxima() 

private:    
  int dni;
  double nota;
  bool amb_nota;
  static const int MAX_NOTA = 10;
  /* 
     Invariant de la representació: 
     - 0 <= dni
     - si amb_nota, llavors 0 <= nota <= MAX_NOTA 
  */

public:
  //Constructores

  Estudiant();
  /* Pre: cert */ 
  /* Post: el resultat és un estudiant amb DNI = 0 i sense nota */

  Estudiant(int dni);
  /* Pre: dni >= 0 */ 
  /* Post: el resultat és un estudiant amb DNI=dni i sense nota */

  // Destructora: esborra automàticament els objectes locals en sortir 
  // d'un àmbit de visibilitat

  ~Estudiant();

  //Modificadores

  void afegir_nota(double nota);
  /* Pre: el paràmetre implícit no té nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del paràmetre implícit passa a ser "nota" */
   
  void modificar_nota(double nota);
  /* Pre: el paràmetre implícit té nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del paràmetre implícit passa a ser "nota" */
                                    
  //Consultores

  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: el resultat és el DNI del paràmetre implícit */

  double consultar_nota() const;
  /* Pre: el paràmetre implícit té nota */
  /* Post: el resultat és la nota del paràmetre implícit */

  static double nota_maxima();
  /* Pre: cert */
  /* Post: el resultat és la nota màxima dels elements de la classe */

  bool te_nota()  const;
  /* Pre: cert  */
  /* Post: el resultat indica si el paràmetre implícit té nota o no */

  static bool comp(const Estudiant& e1, const Estudiant& e2); 
  /* Pre: cert  */
  /* Post: el resultat indica si el DNI d'e1 es més petit que el d'e2 */

  // Lectura i escriptura

  void llegir();
  /* Pre:  hi ha preparats al canal estandar d'entrada un enter no negatiu i un double */
  /* Post: el paràmetre implícit passa a tenir els atributs llegits 
     del canal estàndard d'entrada; si el double no pertany a l'interval 
     [0..nota_maxima()], el p.i. es queda sense nota */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit els atributs del paràmetre implícit 
     al canal estàndard de sortida; si no té nota escriu "NP" */
};
#endif
