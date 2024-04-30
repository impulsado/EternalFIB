#include <vector>
#include <iostream>
using namespace std;

int busqueda_lin(const vector<int>& v, int x) {
    for (int i = 0; i<v.size(); i++) {
        if (v[i]==x) return i;
    }
    return v.size();
}
