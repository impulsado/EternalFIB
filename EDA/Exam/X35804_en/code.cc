#include <iostream>
#include <map>
using namespace std;

struct Info {
  string code;
  int price;
};

int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
      cout << "num: " << M.size() << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      M[length].code = code;
      M[length].price = price;
    }
    else if (c == 'q') {
      int length;
      cin >> length;
      if (M.find(length) == M.end()) cout << -1 << endl;
      else cout << M[length].price << endl;
    }
    else if (c == 'p') {
      cout << string(10, '-') << endl;
      for (auto creuer : M) {
        cout << creuer.second.code << ' ' << creuer.first << ' ' << creuer.second.price << endl;
      }
      cout << string(10, '*') << endl;
    }
    else { // c == 's'
      if (M.size()<2) {cout << "no" << endl; continue;}  // Es aixo el que fa petar eficiencia xd
      auto creuer = M.begin();
      creuer++;
      cout << creuer->second.code << ' ' << creuer->first << ' ' << creuer->second.price << endl;
    }
  }
}