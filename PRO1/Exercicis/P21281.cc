#include <bits/stdc++.h>
using namespace std;

void factor(int n, int& f, int& q) {
  bool is_prime = true;
  int i = 2, counter;

  f = q = counter = 0;

  while ((n/i)>0 and i<=sqrt(n)) {
    while (n%i==0) {
      is_prime = false;
      n = n/i;
      counter++;
    }
    if (counter>q and i>f) f = i, q = counter;
    i++;
    counter = 0;
  }

  if (is_prime) f=n, q=1;
}

int main() {
  int n;
  while (cin >> n) {
    int f = -1, q = 1000;
    factor(n, f, q);
    cout << f << ' ' << q << endl;
  }
  return 0;
}