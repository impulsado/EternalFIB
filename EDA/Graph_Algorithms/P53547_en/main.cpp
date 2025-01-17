#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
                                        // UL      UR      DL      DR
const vector<pair<int,int>> direccions = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};

void askData(vector<vector<string>>& mapa, vector<pair<int,int>>& possibles) {
    for (int i = 0; i<mapa.size(); i++) {
        for (int j = 0; j<mapa[0].size(); j++) {
            cin >> mapa[i][j];
            if (mapa[i][j] != "X") possibles.push_back({i,j});
        }
    }
}

bool ok_vei(const vector<vector<string>>& mapa, int x, int y) {
    if (x<0 || x>=mapa.size()) return false;
    else if (y<0 || y>=mapa[0].size()) return false;
    else if (mapa[x][y] == "X") return false;
    
    return true;
}

int calcSuma(const vector<vector<string>>& mapa, vector<vector<bool>>& vistos, int x_act, int y_act, int& quant) {
    int suma = stoi(mapa[x_act][y_act]);
    vistos[x_act][y_act] = true;
    
    for (const auto& d : direccions) {
        int x_vei = x_act + d.first;
        int y_vei = y_act + d.second;

        if (ok_vei(mapa, x_vei, y_vei) && !vistos[x_vei][y_vei]) {
            quant++;
            suma += calcSuma(mapa, vistos, x_vei, y_vei, quant);
        }
    }

    return suma;
}

bool checkViability(const vector<vector<string>>& mapa, vector<vector<bool>>& vistos, vector<pair<int,int>>& possibles) {
    vector<int> vCCRes;  // Vector guardar resultats de cada components connexes

    for (const auto& pos : possibles) {
        // Ja l'hem visitat
        if (vistos[pos.first][pos.second]) continue;

        // No l'hem visitat així que busquem la suma de la seva component conexa
        int quant_elements = 1;
        int suma = calcSuma(mapa, vistos, pos.first, pos.second, quant_elements);
        
        if (suma%quant_elements != 0) return false;  // No es pot dividir correctament
        vCCRes.push_back(suma/quant_elements);
    }


    // Comprovar que tots tinguin el mateix valor
    for (int i = 1; i<vCCRes.size(); i++) {
        if (vCCRes[i-1] != vCCRes[i]) return false;
    }
    return true;
}

int main() {
    int quant_escenaris;
    cin >> quant_escenaris;

    for (int i = 0; i<quant_escenaris; i++) {
        int n,m;
        cin >> n >> m;

        vector<pair<int,int>> possibles;  // Guardar posicions valides
        vector<vector<string>> mapa(n,vector<string>(m));  // Guardar tot
        vector<vector<bool>> vistos(n,vector<bool>(m, false));  // Guardar registre visitat 
        askData(mapa, possibles);

        if (checkViability(mapa, vistos, possibles)) cout << "Case " << i+1 << ": yes" << endl;
        else cout << "Case " << i+1 << ": no" << endl;
    }
}