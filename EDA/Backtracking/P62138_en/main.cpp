#include <iostream>
#include <vector>

using namespace std;

bool precedencia_ok(const vector<int>& vists, const vector<vector<int>>& precedencies, const int& i) {
    // === BASE CASE
    // No requereix de cap precedencia
    if (precedencies[i].size() == 0) return true;

    // === GENERAL CASE
    // Buscar amb el que han de ser precedents i si algun no l'hem vist, no es pot
    for (auto num : precedencies[i]) if (!vists[num]) return false;

    return true;
}

void solve(vector<int>& tasques, vector<int>& vists, const vector<vector<int>>& precedencies, int t) {
    int n = tasques.size();

    // === BASE CASE
    if (t == n) {
        for (int i = 0; i<n-1; i++) cout << tasques[i] << ' ';
        cout << tasques[n-1] << endl;
        return;
    }

    // === GENERAL CASE
    for (int i = 0; i<n; i++) {
        if (vists[i] || !precedencia_ok(vists, precedencies, i)) continue;
        tasques[t] = i;
        vists[i] = 1;
        solve(tasques, vists, precedencies, t+1);
        vists[i] = 0;
    }

    return;
}


int main() {
    int n, m;
    int x, y;
    int t = 0;
    cin >> n >> m;
    vector<int> tasques(n);
    vector<int> vists(n,0);
    vector<vector<int>> precedencies(n, vector<int>());

    for (int i = 0; i<m; i++) {
        cin >> x >> y;
        precedencies[y].push_back(x);  // x s'ha de fer abans, es a dir, ha de ser vist
    }

    solve(tasques, vists, precedencies, t);
    
    return 0;
}