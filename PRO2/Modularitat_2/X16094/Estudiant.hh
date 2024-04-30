#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#include "PRO2Excepcio.hh"
#include <iostream>

class Estudiant {
    
  // Tipus de modul: dades
  // Descripcio del tipus: conte el DNI d'un estudiant,
  // que es un enter positiu, i pot tenir nota, que seria un double
  // Les notes valides son les de l'interval 0..nota_maxima()
    
private:
  int dni;
  double nota;
  
  static const int MAX_NOTA = 10;
  /*
    Invariant de la representacio:
    - 0 <= dni
    - (escriu aqui la part que falta del nou invariant):
  */
    
public:
  //Constructores
    
  Estudiant();
  /* Pre: cert */
  /* Post: el resultat es un estudiant amb DNI = 0 i sense nota */

  Estudiant(int dni);
  /* Pre: dni >= 0 */
  /* Post: el resultat es un estudiant amb DNI = dni i sense nota */

  //Modificadores

  void afegir_nota(double nota);
  /* Pre: el parametre implicit no te nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del parametre implicit passa a ser "nota" */
    
  void modificar_nota(double nota);
  /* Pre: el parametre implicit te nota, 0 <= "nota" <= nota_maxima() */
  /* Post: la nota del parametre implicit passa a ser "nota" */
    
  //Consultores
    
  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: el resultat es el DNI del parametre implicit */
    
  double consultar_nota() const;
  /* Pre: el parametre implicit te nota */
  /* Post: el resultat es la nota del parametre implicit */
    
  static double nota_maxima();
  /* Pre: cert */
  /* Post: el resultat es la nota maxima dels elements de la classe */
    
  bool te_nota()  const;
  /* Pre: cert  */
  /* Post: el resultat indica si el parametre implicit te nota o no */

  static bool comp(const Estudiant& e1, const Estudiant& e2);
  /* Pre: cert  */
  /* Post: el resultat indica si e1 te DNI mes petit que e2 */

  bool operator==(const Estudiant& est) const;
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. i est tenen el mateix DNI */
  
  bool operator!=(const Estudiant& est) const;
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. i est tenen DNIs diferents */

  // Lectura i escriptura
    
  void llegir();
  /* Pre:  hi ha preparats al canal estandard d'entrada un enter no negatiu 
     i un double */
  /* Post: el parametre implicit passa a tenir els atributs llegits
     del canal estandard d'entrada; si el double no pertany a l'interval
     [0..nota_maxima()], el p.i. es queda sense nota */
    
  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit els atributs del parametre implicit
     al canal estandard de sortida; si no te nota escriu "NP" */
};
#endif
