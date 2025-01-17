#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& v, int z, int u, int i, const int& n) {
    // === BASE CASE
    if (i == n) {
        for (int j = 0; j<n-1; j++) cout << v[j] << ' ';
        cout << v[n-1] << endl;
        return;
    }   

    // === GENERAL CASE
    if (z>0) {
        v[i] = 0;
        solve(v,z-1,u,i+1,n);
    }
    if (u>0) {
        v[i] = 1;
        solve(v,z,u-1,i+1,n);
    }
}

int main() {
    int z, u;
    cin >> z >> u;
    int n = z;
    int i = 0;
    vector<int> v(n);
    solve(v,z-u,u,i,n);
}