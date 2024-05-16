#include "Prenda.hh"

/* Constants */
const char *ER1 = "El pes no pot ser negatiu";

Prenda::Prenda()
{
  peso = 0;
  color = false;
}

Prenda::Prenda(int pes, bool col)
{
  if (pes < 0) throw PRO2Excepcio(ER1);
  peso = pes;
  color = col;
}

void Prenda::modificar(int pes, bool col)
{
  if (pes < 0) throw PRO2Excepcio(ER1);
  peso = pes;
  color = col;
}

int Prenda::consul_peso() const
{
  return peso;
}

bool Prenda::consul_color() const
{
  return color;
}

void Prenda::escribir() const
{
  cout << peso << ' ';
  if (color) cout << "true" << endl;
  else cout << "false" << endl;
}