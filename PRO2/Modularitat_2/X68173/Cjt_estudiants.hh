#ifndef CONJ_EST_HPP
#define CONJ_EST_HPP

#include "Estudiant.hh"
#include <vector>

class Cjt_estudiants { // nomes tenen Pre/Post les noves operacions

private:

  // Representa un conjunt ordenat per DNI d'estudiants.
  
  // Es poden consultar i modificar els seus elements de tipus
  // Estudiant donat un DNI o per posici� en l'ordre.

  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 10001;
  int imax; // nou atribut

  void ordenar_cjt_estudiants ();
  /* Pre: cert */
  /* Post: els elements del par�metre impl�cit estan ordenats
     creixentment pels seus DNI */

  static int cerca_dicot(const vector<Estudiant> &vest, 
			 int left, int right, int x);
  /* Pre: vest[left..right] est� ordenat creixentment per DNI,
     0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el
     resultat �s una posici� que el cont�; si no, el resultat �s -1 */

  void recalcular_posicio_imax();
  /* Pre: cert */
  /* Post: el camp imax cont� la posici� de l'element del par�metre
     impl�cit amb la nota m�s gran */

public:

  //Constructores

  Cjt_estudiants();

  //Modificadores

  void afegir_estudiant(const Estudiant& est);

  void modificar_estudiant(const Estudiant& est);

  void modificar_iessim(int i, const Estudiant& est);

  void esborrar_estudiant(int dni);
  /* Pre: existeix un estudiant al par�metre impl�cit amb DNI = dni */
  /* Post: el par�metre impl�cit cont� els mateixos estudiants que
     l'original menys l'estudiant amb DNI = dni */

  // Consultores
	
  int mida() const;

/*
*/
  int consultar_imax() const;

  static int mida_maxima();

  bool existeix_estudiant(int dni) const;

  Estudiant consultar_estudiant(int dni) const;

  Estudiant consultar_iessim(int i) const;

  Estudiant estudiant_nota_max() const;
  /* Pre: el par�metre impl�cit cont� almenys un estudiant amb nota */
  /* Post: el resultat �s l'estudiant del par�metre impl�cit amb nota
     m�xima; si en t� m�s d'un, �s el de DNI m�s petit */ 
 		
  // Lectura i escriptura
	
  void llegir();

  void escriure() const;

};
#endif
