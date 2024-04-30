#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  nest_amb_nota = 0;
  suma_notes = 0;
}

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
    cout << "PRE: " << vest.size() << endl;
    vest.erase(vest.begin()+pos);
    cout << "POST: " << vest.size() << endl;
    nest--;
  }
  else {
    b = false;
  }
}
// === FI NOVES IMPLEMENTACIONS

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x) {
  int i; 
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  } 
  if (found) return i;
  else return left;
}  

int Cjt_estudiants::mida() const {
  return nest;
}

int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

double Cjt_estudiants::mitjana_estudiants_amb_nota() const {
  if (nest_amb_nota == 0)
    return -1;
  else
    return suma_notes/nest_amb_nota;
}

void Cjt_estudiants::ordenar_cjt_estudiants () {
  sort(vest.begin(),vest.begin()+nest,Estudiant::comp);
}

void Cjt_estudiants::llegir() {
  //cout << "Escriu la mida del conjunt i els elements" << endl;
  cin >> nest;
  nest_amb_nota = 0;
  suma_notes = 0;
  for (int i=0; i<nest; ++i) {
    vest[i].llegir();
    if (vest[i].te_nota()) {
      ++nest_amb_nota; 
      suma_notes += vest[i].consultar_nota();
    }
  }
  ordenar_cjt_estudiants();
}

void Cjt_estudiants::escriure() const{
  for (int i=0; i<nest; ++i) vest[i].escriure();
  //cout << suma_notes << " " << nest_amb_nota << endl;
}
