#include <iostream>
using namespace std;

int max (int n, int m) {
  if (n>=m) return n;
  else return m;
}

int fatten(int x) {
  int res;
  res = 0;
  
  if (x<10) return x;
  else {
    res = fatten(x/10);
    cout << res;
    return max(x%10,res%10);
  }
}

int main() {
  int x;
  while (cin >> x) cout << fatten(x) << endl;
}