#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, contadorLeft = 0, contadorRight = 1, max = 0, w_counter = 0, end = 0;

    while (cin >> usr_num) {
        // Maxim columnes = files
        contadorRight = 1;
        max = contadorLeft = usr_num;
        for (int i = 1; i<usr_num; i++) {
            max = max + 2;
        }
        
        for (int fila = 1; fila<=max; fila++) {
            if (fila >= (usr_num*2)) contadorLeft = usr_num - (max-fila);
            for (int col = 1; col<=max; col++) {
                if (end == 0) {
                    // Espais Laterals
                    if ((fila <= (usr_num-col)) and (col <= (usr_num-fila))) {cout << ' '; continue;}
                    if ((fila >= (usr_num*2)) and (col < contadorLeft)) {cout << ' '; continue;}
                    
                    // Salts de linea
                    if ((col > (max-usr_num+fila)) and fila < (usr_num)) {cout << endl; end = 1; continue;}  // usr_num+contadorLeft creec que tambe
                    if (col == max) {cout << "X" << endl; end = 1; continue;}
                    if ((fila >= (usr_num*2)) and (col >= (max-contadorRight))) {contadorRight = contadorRight + 1; cout << "X" << endl; end = 1; continue;}
                    
                    // X
                    cout << 'X';

                    contadorLeft = contadorLeft + 1;  // Espais en blanc de la part inferior
                }
            }
            end = 0;
        }
        cout << endl;  // Salt entre formes
    }
}