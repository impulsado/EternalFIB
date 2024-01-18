#include <iostream>
using namespace std;


void cross(int n, char c) {
  int e_quant;
  for (int fila = 1; fila<=n; fila++) {
    e_quant = n/2;

    if (fila == (n/2)+1) {  // Fer fila centro
      for (int i = 1; i<=n; i++) cout << c;
      cout << endl;
    } else {  // Resta files
      while (e_quant>0) e_quant--, cout << ' ';
      cout << c << endl;
    }
  }
}


int main() {
  int n;
  char c;
  while (cin >> n >> c) cross(n, c);
  return 0;
}
