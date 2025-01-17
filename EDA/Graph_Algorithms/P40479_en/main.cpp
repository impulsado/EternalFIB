#include <vector>
#include <string>
#include <iostream>
using namespace std;
                                        // U       D      L       R
const vector<pair<int,int>> direccions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void showMap(const vector<vector<char>>& mapa) {
    for (int i = 0; i<mapa.size(); i++) {
        for (int j = 0; j<mapa[0].size()-1; j++) {
            cout << mapa[i][j];
        }
        cout << mapa[i][mapa[0].size()-1] << endl;
    }
}

void askData(vector<vector<char>>& mapa, vector<pair<pair<int,int>,char>>& inicials) {
    for (int i = 0; i<mapa.size(); i++) {
        for (int j = 0; j<mapa[0].size(); j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] != '#' && mapa[i][j] != '.') inicials.push_back({{i,j}, mapa[i][j]});
        }
    }
}

bool ok_vei(const vector<vector<char>>& mapa, int x, int y) {
    if (x<0 || x>=mapa.size()) return false;
    else if (y<0 || y>=mapa[0].size()) return false;
    else if (mapa[x][y] == '#') return false;
    
    return true;
}

void paintMap(vector<vector<char>>& mapa, int x_a, int y_a, const char lletra) {
    for (const auto& d : direccions) {
        int x_v = x_a + d.first;
        int y_v = y_a + d.second;

        if (ok_vei(mapa, x_v, y_v) && (mapa[x_a][y_a] != mapa[x_v][y_v])) {
            mapa[x_v][y_v] = lletra;
            paintMap(mapa, x_v, y_v, lletra);
        }
    }
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        vector<pair<pair<int,int>,char>> inicials;  // Guardar posicions inicials
        vector<vector<char>> mapa(n,vector<char>(m));  // Guardar tot
        askData(mapa, inicials);

        for (const auto& pos : inicials) {
            paintMap(mapa, pos.first.first, pos.first.second, pos.second);
        }

        showMap(mapa);
        cout << endl;
    }
}