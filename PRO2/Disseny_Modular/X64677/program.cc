#include <iostream>
#include "Prenda.hh"
#include "Cubeta.hh"
#include "Lavadora.hh"
#include "readbool.hh"
using namespace std;

int main()
{
  Lavadora lav;
  Cubeta cub;

  int opcion;
  cin >> opcion;
  while (opcion != -8) {    
    if (opcion == -1) { // inicializar lavadora (datos: peso máximo y color)
      int peso_max;
      cin >> peso_max;
      bool color = readbool();

      lav.inicializar(peso_max, color);
    }
    else if (opcion == -2) { // añadir una prenda a la lavadora (datos: peso  y color de la prenda)
      int peso;
      cin >> peso;
      bool color = readbool();

      lav.anadir_prenda(Prenda(peso, color));
    }
    else if (opcion == -3) { // añadir una prenda a la cubeta (datos: peso  y color de la prenda)
      int peso;
      cin >> peso;
      bool color = readbool();

      cub.anadir_prenda(Prenda(peso, color));
    }
    else if (opcion == -4) { // completar la lavadora
      cub.completar_lavadora(lav);
    }
    else if (opcion == -5) { // realizar un lavado
      lav.lavado();
    }
    else if (opcion == -6) { // escribir el contenido de la cubeta
      cub.escribir();
      cout << endl;
    }
    else if (opcion == -7) { // escribir el contenido de la lavadora
      lav.escribir();
      cout << endl;
    }
    cin >> opcion;
  }
}