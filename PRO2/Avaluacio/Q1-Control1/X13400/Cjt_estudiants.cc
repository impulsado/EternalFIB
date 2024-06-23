#include <algorithm>
#include <iostream>
#include "Cjt_estudiants.hh"
#include "PRO2Excepcio.hh"

using namespace std;

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  intervals = vector<int> (10, 0);
}

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
    vest.erase(vest.begin()+pos);
    nest--;
  }
  else {
    b = false;
  }
}
// === FI NOVES IMPLEMENTACIONS

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  int i;
  bool found=false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1; 
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  } 
  if (found) return i;
  else return left;
}  

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima() 
{
  return MAX_NEST;
}
 
int Cjt_estudiants::nombre_est_interval(int i) const
{
  return intervals[i];
}

void Cjt_estudiants::ordenar() {
  sort(vest.begin(), vest.begin() + nest, Estudiant::comp);
}

void Cjt_estudiants::llegir() {
  cin >> nest; 
  for (int i = 0; i < nest; ++i) {
    vest[i].llegir();
    if (vest[i].te_nota()) {
      incrementar_interval(vest[i].consultar_nota());
    }
  }
  ordenar();
}

void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

