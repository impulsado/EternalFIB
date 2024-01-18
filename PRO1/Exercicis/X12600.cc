#include<bits/stdc++.h>
using namespace std;

int main () {
    bool possible = true;
    int usr_espais, usr_quantitat, e_quant=0, x_quant=0, a_quant=0, max_a=0;

    while (cin >> usr_espais >> usr_quantitat) {
        e_quant = x_quant = a_quant = max_a = 0;  // Reset Contadors per nou dibuix
        possible = true;   // Reset variable auxiliar per no fer brake

        for (int i = 1; i<=usr_quantitat; i++) {
            // Files Creixent
            for (int fila_c = 0; fila_c<=usr_espais-1; fila_c++) {
                // Fila Primera
                if (fila_c==0) {
                    e_quant = usr_espais;
                    while (e_quant>0) cout << ' ', e_quant--;
                    cout << '*' << endl;
                    continue;  // Saltar tota la resta
                }

                possible = true;
                e_quant = usr_espais - fila_c;  // Quantitat Espais fila
                a_quant = 2*fila_c-1;
            
                for (int col_c = 1 ; col_c<=usr_espais*2+1; col_c++) {
                    while (possible==true) {
                        while (e_quant>0) cout << ' ', e_quant--;
                        cout << '*';
                        while (a_quant>0) cout << ' ', a_quant--;
                        cout << '*';
                        if (e_quant==0 and a_quant==0) possible = false, cout << endl;
                    }
                }
            }
            
            // Fila Màxima
            for (int col_t = 1; col_t <= usr_espais*2+1; col_t++) {
                if (col_t == 1 or col_t == usr_espais*2+1) cout << '*'; else cout << ' ';
                if (col_t == usr_espais*2+1) cout << endl;
            }

            // Files Decreixent
            max_a = usr_espais*2-1;
            for (int fila_d = 1; fila_d <= usr_espais-1; fila_d++) {
                possible = true;
                e_quant = fila_d;
                max_a=max_a-2;
                a_quant = max_a;
                for (int col_d = 1; col_d <= usr_espais*2+1; col_d++) {
                    while (possible == true) {
                        while (e_quant>0) cout << ' ', e_quant--;
                        cout << '*';
                        while (a_quant>0) cout << ' ', a_quant--;
                        cout << '*';
                        if (e_quant==0 and a_quant==0) possible = false, cout << endl;
                    }
                }
            }

            // Fila Última
            if (i==usr_quantitat) {
                e_quant = usr_espais;
                while (e_quant>0) cout << ' ', e_quant--;
                cout << '*' << endl;
            }
        }
        cout << endl;  // Espais entre dibuixos complets
    }
}