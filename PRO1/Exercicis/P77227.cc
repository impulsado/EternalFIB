#include <iostream>
#include <vector>
using namespace std;

string sortida(int p, vector<int>& v) {
  /*
  La cosa està en que no expliquen una merda.
  Si veus un valor el marques com a '0' perque en aquesta casella ja has estat
  Necessites una nova variable next_pos perque sino, al fer p[v]=0 a la seguent faria "mai"
  */
  while (true) {
    int next_pos = v[p] + p;
    if (next_pos<0) return "esquerra";
    if (next_pos>=v.size()) return "dreta";
    if (v[next_pos]==0) return "mai";
    v[p] = 0;
    p = next_pos;
  }
}

int main() {
  int p, n;
  while (cin >> p >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << sortida(p, v) << endl;
  }
  return 0;
}
