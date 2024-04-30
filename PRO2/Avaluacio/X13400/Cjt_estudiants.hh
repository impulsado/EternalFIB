#ifndef CONJ_EST_HH
#define CONJ_EST_HH

#include <vector>
#include <iostream>
#include "Estudiant.hh"

using namespace std;

class Cjt_estudiants {

private:

  // Representa un conjunt d'estudiants ordenat per DNI.  
  
  vector<Estudiant> vest; // estudiants del conjunt

  int nest; // nombre d'estudiants del conjunt 

  static const int MAX_NEST = 1500000; // nombre maxim d'elements del conjunt

  vector<int> intervals; // nombre d'estudiants del conjunt a cada interval:

  /* 
     Invariant de la representació: 
     - vest[0..nest-1] està ordenat creixentment pel dni dels estudiants i no conté estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
     - intervals.size() = 10
     - per a tot i entre 0 i 8, intervals[i] és el nombre d'estudiants de vest[0..nest-1] que satisfan i <= nota < i + 1   
     - intervals[9] és el nombre d'estudiants de vest[0..nest-1] que satisfan 9 <= nota <= 10
  */
 
  void ordenar();
  /* Pre: cert */
  /* Post: el elements del paràmetre implícit passen a estar ordenats
     creixentment per DNI. */
     
  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: els elements de vest estan ordenats creixentment per DNI,
     0 <= left, right < vest.size(), right >= left + 1 */
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

   
  void incrementar_interval(double x);
  /* Pre: x és una nota vàlida */
  /* Post: al paràmetre implícit, s'ha incrementat en una unitat el valor de
     la posició d'"intervals" corresponent a x */

  void decrementar_interval(double x);
  /* Pre: x és una nota vàlida */
  /* Post: al paràmetre implícit, s'ha decrementat en una unitat el valor de
     la posició d'"intervals" corresponent a x */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: El resultat és el nombre d'estudiants del paràmetre implícit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat és el nombre maxim d'estudiants que pot arribar
     a tenir el paràmetre implícit */

  int nombre_est_interval(int i) const;
  /* Pre: 0 <= i <= 9 */
  /* Post: el resultat és el nombre d'estudiants del paràmetre implícit amb
     nota a l'interval i */

  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal estàndar d'entrada un enter  (entre 0 i la
     mida maxima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el paràmetre implícit conté el conjunt d'estudiants llegits
     del canal estàndar d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal estàndar de sortida els estudiants del
     paràmetre implícit en ordre ascendent per DNI */
};

#endif

