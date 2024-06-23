#include <iostream>
#include "PRO2Excepcio.hh"
#include "Estudiant.hh"

using namespace std;

/* Constantes */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  amb_nota = false;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  amb_nota = false;
}

Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double nota)
{
  if (amb_nota) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
  amb_nota = true;
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (not amb_nota) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return amb_nota;
}

double Estudiant::consultar_nota() const
{
  if (not amb_nota) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni; 
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
    amb_nota = true;
  }
  else amb_nota = false;
}

void Estudiant::escriure() const
{
  if (amb_nota)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}

bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2) 
{
  return e1.dni< e2.dni;
} 

