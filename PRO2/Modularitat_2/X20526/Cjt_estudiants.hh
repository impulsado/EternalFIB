#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest;
  int nest; 
  static const int MAX_NEST = 10001; // nombre maxim d'elements del conjunt
  int nest_amb_nota;  
  double suma_notes;

  /* 
     Invariant de la representació: 
     - vest[0..nest-1] està ordenat creixentment pel DNI dels estudiants
       i no conté estudiants repetits
     - 0 <= nest_amb_nota <= nest <= vest.size() = MAX_NEST
     - nest_amb_nota és el nombres d'estudiants amb nota de vest[0..nest-1]
     - suma_notes és la suma de les notes (dels estudiants amb nota) de vest[0..nest-1]
  */  
    
  void ordenar_cjt_estudiants();
  /* Pre: cert */
  /* Post: el elements del paràmetre implícit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0<=left, right<vest.size(), right>=left-1 */
  /* Post: si x hi és vest[left..right], el resultat és la posició que
     hi ocupa, si no, és la posició que hauria d'ocupar */
 
  
public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: crea un conjunt d'estudiants buit */

  //Modificadores

  void afegir_estudiant(const Estudiant &est, bool& b);
  /* Pre: el paràmetre implícit no està ple */
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

  void esborrar_estudiant(int dni, bool& b);
  /* Pre: cert */
  /* Post: b indica si el paràmetre implícit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del paràmetre implícit */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat es el nombre maxim d'estudiants que pot arribar
     a tenir el parametre implicit */
  
  double mitjana_estudiants_amb_nota() const;
  /* Pre: cert */
  /* Post: el resultat és la mitjana de les notes dels estudiants amb nota
     del paràmetre implícit; si no n'hi ha cap, el resultat és -1 */ 

  // Lectura i escriptura
	
  void llegir();
  /* Pre: cert */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndar de sortida 
     els estudiants del conjunt que conté el paràmetre 
     implícit en ordre ascendent per DNI */

};

#endif
