// pau.bru@estudiantat.upc.edu L43
// jaime.prieto@estudiantat.upc.edu L43
#include "Cjt_estudiants.hh"

// === NOVES IMPLEMENTACIONS
void Cjt_estudiants::incrementar_interval(double x) {
  // IMPO: El Pre diu que x sempre serà valid aixi que no fa falta comprovar-ho
  int index_nota = int(x);
  if (index_nota==10) intervals[9]++;
  else intervals[index_nota]++;
}

void Cjt_estudiants::decrementar_interval(double x) {
  // IMPO: El Pre diu que x sempre serà valid aixi que no fa falta comprovar-ho
  int index_nota = int(x);
  if (index_nota==10) intervals[9]--;
  else intervals[index_nota]--;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
  int dni = est.consultar_DNI();
  int pos = cerca_dicot(vest,0,nest-1,dni);
  
  // "pos<nest" serveix perque si el alumne hauria d'estar al final de la llista passara que pos=nest 
  // i si no controlem aquest cas, podriem fer vest[pos].consultar_DNI() pero en aquella pos no hi ha
  // un alumne valid.
  if (pos<nest and vest[pos].consultar_DNI()==dni) b = true;
  else {
    b = false;
    // Moure cap amunt tots els estudiants que tenen dni mes gran que est
    for (int i = nest-1; i>=pos; i--) vest[i+1] = vest[i];
    // Ficar a est on li toca
    vest[pos] = est;
    ++nest;
    // Afegir nou estudiant a l'interval que pertoca
    if (est.te_nota()) incrementar_interval(est.consultar_nota());
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
  int pos = cerca_dicot(vest,0,nest-1,dni);
  if (pos<nest and vest[pos].consultar_DNI()==dni) {
    b = true;
    if (vest[pos].te_nota()) decrementar_interval(vest[pos].consultar_nota());
    // Aixo "baixa" els alumnes que estaven per sobre del eliminiat sobre escribint-se
    /*
    NOTA: Estava intentant fer-ho amb .erase() pero em petava per eficiencia. 
    En aquest cas (probablement) es degut a que .erase() toca l'estructura del vector i fa comprovacions
    que en aquest context simple afegeixen carrega inneccessaria. A sobre, toca la grandaria del vector
    fent que si hi haguessin MAX_NEST estudiants i despres s'eliminessin tots el tamany del vector seria 0.
    */  
    for (int i = pos; i<nest-1; i++) vest[i] = vest[i+1];
    nest--;
  }
  else {
    b = false;
  }
}
// === FI NOVES IMPLEMENTACIONS