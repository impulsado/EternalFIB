#include <iostream>
using namespace std;

int main() {
    // INFORMACIÓ INICIAL
    int usr_quant, usr_lim;
    cin >> usr_quant >> usr_lim;

    int usr_num, suma = 0;
    string post_lim;
    for (int i = 1; i<=usr_quant; i++) {
        while (cin >> usr_num) {
            if (usr_num == usr_lim) {  
                getline(cin,post_lim);  // Guardar en una variable el contingut post-limit que no serveix per res.
                break;  // Sortir del bucle de "cin >> usr_num" 
            }
            suma += usr_num;
        }
        // MOSTRAR RESULTAT
        cout << "La suma de la secuencia " << i << " es " << suma << endl;
        suma = 0;
    }
}