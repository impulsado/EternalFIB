#include <iostream>
using namespace std;

void rombo (int counter, bool puntes, int max_size) {
    /*
    Counter --> Alçada del rombo específic (Quantiat de files).
    Puntes --> Quan és el màxim, aquest no té punta superior ni inferior.
    Max_size --> Determinar la quantitat d'espais que es necessiten perquè rombes estiguin centrats. Ho determina el número de l'usuari. 
    */

    if (puntes) {
        for (int i = 1; i<=counter; i++) {  // SUPERIOR
            for (int j = 1; j<=max_size-i; j++) {  // Espais
                cout << ' ';
            }
            for (int j = 1; j<=i; j++) {  // Esquerra
                cout << '*';
            }
            for (int j = 1; j<i; j++) {  // Dreta - 1
                cout << '*';
            }
            cout << endl;
        }
        
        for (int i = 1; i<counter; i++) {  // INFERIOR
            for (int j = 1; j<=max_size-counter+i; j++) {  // Espais
                cout << ' ';
            }
            for (int j = i; j<counter; j++) {  // Esquerra
                cout << '*';
            }
            for (int j = i; j<counter-1; j++) {  // Dreta - 1
                cout << '*';
            }
            cout << endl;
        }
    } else {
        // Si es vol treure la punta inicial --> i = 2
        for (int i = 2; i<=counter; i++) {  // SUPERIOR
            for (int j = 1; j<=max_size-i; j++) {  // Espais
                cout << ' ';
            }
            for (int j = 1; j<=i; j++) {  // Esquerra
                cout << '*';
            }
            for (int j = 1; j<i; j++) {  // Dreta - 1
                cout << '*';
            }
            cout << endl;
        }
        // Si es vol treure la punta final --> counter-1
        for (int i = 1; i<counter-1; i++) {  // INFERIOR
            for (int j = 1; j<=max_size-counter+i; j++) {  // Espais
                cout << ' ';
            }
            for (int j = i; j<counter; j++) {  // Esquerra
                cout << '*';
            }
            for (int j = i; j<counter-1; j++) {  // Dreta - 1
                cout << '*';
            }
            cout << endl;
        }
    }
}

void repeticions(int counter, int usr_num) {
    // Cas Base
    if (counter==1) {rombo(1,true,usr_num); return;}

    repeticions(counter-1,usr_num);
    rombo(counter,false,usr_num); // Central
    repeticions(counter-1,usr_num);
}

int main () {
    int usr_num, counter = 1;

    while (cin >> usr_num) {
        // Cassos Especials
        if (usr_num == 1) {cout << '*' << endl << endl; continue;}
        counter = usr_num;


        repeticions(counter,usr_num);
        cout << endl; // Salt de linia entre formes de rombos.
    }
}