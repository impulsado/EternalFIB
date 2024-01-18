#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<bool> > Tauler;

int searchShip(const Tauler& mapa, int row, int col) {
    int rows = mapa.size();
    int cols = mapa[0].size();

    for (int dist = 1; dist<=10; dist++) {
        for (int i=-dist; i<=dist; i++) {
            for (int j=-dist; j<=dist; j++) {
                if (i==0 and j==0) continue;  // És ell mateix
                int newRow = row+i;
                int newCol = col+j;
                if ((0<=newRow and newRow<rows) and (0<=newCol and newCol<cols)) {
                    if (mapa[newRow][newCol]==true) return dist;
                }
            }
        }
    }

    return 10;
}

void askCoordenates(Tauler& mapa) {
    char usr_row;
    int col, row;
    int dist;

    while (cin >> usr_row >> col) {
        row = usr_row-'a'; col = col-1;  // Adaptar coordenades
        
        if (mapa[row][col]==true) cout << usr_row << col+1 << " tocat!" << endl;
        else {
            dist = searchShip(mapa, row, col);  // Buscar barco més pròxim
            cout << usr_row << col+1 << " aigua! vaixell mes proper a distancia " << dist << endl;
        }        
    }
}

void showMap(Tauler& mapa) {
    cout << "  "; for (int i = 1; i<=10; i++) cout << i; cout << endl; // Números superiors

    for (int row = 0; row<10; row++) {
        char lletra = row+97; cout << lletra << ' ';  // Lletra Lateral

        for (int col = 0; col<10; col++) {  // Contingut
            if (mapa[row][col]==true) cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}

void setShip(Tauler& mapa, int row, int col, int length, char orientation) {
    if (orientation=='h') {  // Horizontal
        for (int i = 0; i<length; i++) {
            mapa[row][col] = true;
            col++;
        }
    } else {  // Vertical
        for (int i = 0; i<length; i++) {
            mapa[row][col] = true;
            row++;
        }
    }
}

void askInfo(Tauler& mapa) {
    char usr_row, orientation;
    int length, row, col;
    for (int i = 0; i<10; i++) {
        cin >> usr_row >> col >> length >> orientation;
        row = usr_row-'a'; col = col-1;  // Adaptar coordenades
        setShip(mapa, row, col, length, orientation);  // Colocar barco
    }
}

int main() {
    Tauler mapa(10,vector<bool>(10));
    askInfo(mapa);
    showMap(mapa);
    askCoordenates(mapa);
}