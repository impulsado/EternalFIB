#include "Lavadora.hh"

/* Constants */
const char *ER2 = "La lavadora no está inicializada";
const char *ER3 = "El peso máximo debe ser mayor que 0";
const char *ER4 = "La lavadora y la prenda deben ser del mismo color";
const char *ER5 = "No se puede superar el peso máximo de la lavadora";

Lavadora::Lavadora()
{
  // prendas = list<Prenda>();
  pes = 0;
  ini = false;
}

void Lavadora::inicializar(int pmax, bool col)
{
  if (pmax < 0) throw PRO2Excepcio(ER3);
  prendas = list<Prenda>();
  this->col = col;
  pesmax = pmax;
  ini = true;
}

void Lavadora::anadir_prenda(const Prenda& p)
{
  if (not ini) throw PRO2Excepcio(ER2);
  if (p.consul_color() != col) throw PRO2Excepcio(ER4);
  if (p.consul_peso() + pes > pesmax) throw PRO2Excepcio(ER5);

  // prendas.insert(prendas.end(), p);
  prendas.push_back(p);
  pes += p.consul_peso();
}

void Lavadora::lavado()
{
  if (not ini) throw PRO2Excepcio(ER2);
  prendas = list<Prenda>(); // porque razón seria lineal?
  // vale igual está asignación lo es ya que debe reasignar los punteros de toda la lista antigua o algo así ¿?
  ini = false;
  pes = 0;
}

bool Lavadora::esta_inicializada() const
{
  return ini;
}

bool Lavadora::consultar_color() const
{
  return col;
}

int Lavadora::consultar_peso() const
{
  return pes;
}

int Lavadora::consultar_peso_maximo() const
{
  return pesmax;
}

void Lavadora::escribir() const
{
  cout << "   Lavadora: " << endl;
  if (ini) {
    string tipo = consultar_color() ? "color" : "blanco"; // if true -> color, if false -> blanco.
    cout << "Lavadora de " << tipo << ", con peso actual " << pes;
    cout << " y peso maximo " << pesmax << "; " << "sus prendas son" << endl;
    for (list<Prenda>::const_iterator it = prendas.cbegin(); it != prendas.cend(); ++it)
      it->escribir();
  }
  else cout << "Lavadora no inicializada" << endl;
}