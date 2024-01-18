#include <typeinfo>
#include <iostream>
using namespace std;

struct Racional {
  int num, den;
};

void swap(int& a, int& b) {
  int tmp;
  tmp = a; a = b; b = tmp;
}

int mcd(int a, int b) {
  int r;
  if (a<0) a = a*(-1);  // El denominador ja l'hem tractat previament
  if (a<b) swap(a,b);

  r = a%b;
  while (r!=0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

Racional racional(int n, int d) {
  Racional r;
  int div_comu = 1;
  if (n==0) d = 1;
  else {
    if (d<0) d = d*(-1), n = n*(-1);  // Busquem tindre el denominador positiu.
    div_comu = mcd(n,d);
  }
  
  n /= div_comu; d /= div_comu;  // Simplificar
  r.num = n; r.den = d;  // Guardar el racional normalitzat

  return r;
}

int main() {
  int num, den;
  while (cin >> num >> den) {
    Racional r = racional(num, den);
    cout << r.num << " " << r.den << endl;
  }
  return 0;
}
