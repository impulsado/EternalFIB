#include <iostream>
using namespace std;


int sum_min_max(int x,int y,int z) {
  int maxim, minim;

  if (x>=y) {
    if (x>=z) maxim = x; else maxim = z;
    if (y>=z) minim = z; else minim = y;
  } else {
    if (y>=z) maxim = y; else maxim = z;
    if (x>=z) minim = z; else minim = x; 
  }

  return minim+maxim;
}


int main() {
  int x,y,z;
  while (cin >> x >> y >> z) cout << sum_min_max(x,y,z) << endl;
}
