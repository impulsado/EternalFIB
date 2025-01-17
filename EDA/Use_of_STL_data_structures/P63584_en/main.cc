#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct element {
  int value;
  int index;
  int vector_id;
};

struct customComp {
  bool operator()(const element& e1, const element& e2) const {
    return e1.value > e2.value;
  }
};

int k_esim(int k, const vector<vector<int> >& V) {
  vector<int> registre(V.size());
  priority_queue<element, vector<element>, customComp> millors;

  for (int i = 0; i<V.size(); i++) {
    if (!V[i].empty()) {
      element temp;
      temp.value = V[i][0];
      temp.vector_id = i;
      temp.index = 0;
      registre[i] = 0;
      millors.push(temp);
    }
  }

  int resultat = 0;

  for (int i = 0; i<k-1 and !millors.empty(); i++) {
    element top = millors.top();
    millors.pop();

    if (millors.empty()) resultat = top.value;

    if (top.index<V[top.vector_id].size()-1) {
      registre[top.vector_id]++;
      element next_element;
      next_element.value = V[top.vector_id][registre[top.vector_id]];
      next_element.index = registre[top.vector_id];
      next_element.vector_id = top.vector_id;
      millors.push(next_element);
    }
  }
  
  if (!millors.empty()) return millors.top().value;
  else return resultat;
}

int main() {
  int n;
  while (cin >> n) {
    vector<vector<int> > V(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      total += m;
      V[i] = vector<int>(m);
      for (int j = 0; j < m; ++j) cin >> V[i][j];
    }

    int k;
    cin >> k;
    cout << k_esim(k, V) << endl;
    /*
    int i1, i2, k;
    while (cin >> i1 >> i2 >> k, i1 != -1) {
      if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
        cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n
             << ' ' << total << endl;
        return 0;
      }

      swap(V[i1], V[i2]);
      cout << k_esim(k, V) << endl;
    }
    */
  }
}
