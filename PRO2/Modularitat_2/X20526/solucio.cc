#include "Cjt_estudiants.hh"

// === NOVES IMPLEMENTACIONS
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
    
    if (est.te_nota()) {
      nest_amb_nota++;
      suma_notes += est.consultar_nota();
    }
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
  int pos = cerca_dicot(vest,0,nest-1,dni);
  if (pos<nest and vest[pos].consultar_DNI()==dni) {
    b = true;
    if (vest[pos].te_nota()) {
      nest_amb_nota--;
      suma_notes -= vest[pos].consultar_nota();
    }
    vest.erase(vest.begin()+pos);
    nest--;
  }
  else {
    b = false;
  }
}
// === FI NOVES IMPLEMENTACIONS