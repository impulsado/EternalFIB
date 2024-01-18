#include <iostream>
using namespace std;

int mcd(int num, int den) {
  // Algoritme de euclides
  int res = 1;

  while (res!=0) {
    res = num%den;
    if (res != 0) {
      num = den;
      den = res;
    } else {
      return den;
    }
  }

  return den;
}

void read_rational(int& num, int& den) {
  int valor_comu;
  char barra;

  cin >> num >> barra >> den;

  valor_comu = mcd(num,den);

  num = num/valor_comu;
  den = den/valor_comu;
}

int main() {
  int num, den;
  read_rational(num, den);
  cout << num << ' ' << den << endl;
}

/*
int mcd(int num, int den) {
  int tempo;

  while (den>0) {
    tempo = den;
    den = num%den;
    num = tempo;
  }

  return num;
}
*/

/* EE: TLE
#include <iostream>
using namespace std;

int mcd(int num, int den) {
  bool possible = true;
  int simp=2, minim, valor=1, tmp_num, tmp_den;

  tmp_num = num;
  tmp_den = den;
  
  if ((tmp_num==1 and tmp_den==1) or tmp_num==tmp_den) return tmp_num;

  // Saber quin es el més petit
  if (tmp_num>=tmp_den) minim = tmp_den; else minim = tmp_num;

  while (possible) {
    if (tmp_num%simp==0 and tmp_den%simp==0) {
      tmp_num = tmp_num/simp; tmp_den = tmp_den/simp; valor = valor*simp; continue;
    } else {
      if (simp>minim) possible = false; else simp++;
    }
  }

  return valor;
}

void read_rational(int& num, int& den) {
  int valor_comu;
  char barra;

  cin >> num >> barra >> den;

  valor_comu = mcd(num,den);

  num = num/valor_comu;
  den = den/valor_comu;
}

int main() {
  int num, den;
  read_rational(num, den);
  cout << num << ' ' << den << endl;
}
*/