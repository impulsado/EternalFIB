#include "Cubeta.hh"

/* Constants */
const char *ER6 = "La lavadora no está inicializada";

Cubeta::Cubeta()
{
  ropacolor = stack<Prenda>();
  ropablanca = stack<Prenda>();
}

Cubeta::Cubeta(const Cubeta& c)
{
  ropacolor = c.ropacolor;
  ropablanca = c.ropablanca;
}

// recursive version
// static
void Cubeta::completar_lavadora_pila_rec(stack<Prenda>& p, Lavadora& l)
{
  if (not p.empty() and l.consultar_peso() + p.top().consul_peso() <= l.consultar_peso_maximo())
  {
    l.anadir_prenda(p.top());
    p.pop();
    completar_lavadora_pila_rec(p, l);
  }
}

// iterative version
// static
void Cubeta::completar_lavadora_pila_it(stack<Prenda>& it, Lavadora& l)
{
  int peso = l.consultar_peso();
  int peso_max = l.consultar_peso_maximo();

  while (not it.empty() and peso + it.top().consul_peso() <= peso_max)
  {
    l.anadir_prenda(it.top());
    peso += it.top().consul_peso();
    it.pop();
  }
}

// static, no entiendo como va esto del static sinceramente
void Cubeta::escribir_pila_prenda(const stack<Prenda>& p)
{
  stack<Prenda> paux = p;  
  while (not paux.empty())
  {
    paux.top().escribir();
    paux.pop();
  }
}

void Cubeta::anadir_prenda(const Prenda& p)
{
  if (p.consul_color()) ropacolor.push(p);
  else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav)
{
  if (not lav.esta_inicializada()) throw PRO2Excepcio(ER6);
  if (lav.consultar_color()) completar_lavadora_pila_it(ropacolor, lav);
  else completar_lavadora_pila_it(ropablanca, lav);
}

void Cubeta::escribir() const
{
  cout << "   Cubeta: " << endl;
  cout << "Ropa de color de la cubeta: " << endl;
  escribir_pila_prenda(ropacolor);
  cout << "Ropa blanca de la cubeta: " << endl;
  escribir_pila_prenda(ropablanca);
}