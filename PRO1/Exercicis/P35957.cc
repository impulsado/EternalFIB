#include <iostream>
using namespace std;

int main () {
    string winner = "=";
    int usr_quant=1, usr_num, xifres = 1, digit=0, potencia = 1, turno = 1;

    cin >> usr_quant;

    while (turno<=2*usr_quant) {
       //cout << "TURNO: " << turno << " DIGIT: " << digit << " TURNOS: " << 2*usr_quant << " WINNER: " << winner << endl;

        cin >> usr_num;
        
        //cout << "XIFRES: " << xifres << endl;
        
        // Algu dels dos ha escrit un nombre parell de digits
        if (winner=="=") {
            // Quantitat de digits del numero
            for (int div = 10; (usr_num/div)>0; div = div*10) xifres++;
            //cout << "XIFRES: " << xifres << endl;

            if (xifres%2==0 and turno%2==0) winner = "A";
            if (xifres%2==0 and turno%2==1) winner = "B";
        }

        if (winner=="=") {
            for (int i = 1; i<=(xifres/2); i++) potencia = potencia * 10;
            //cout << "POTENCIA: " << potencia << " DIGIT ACTUAL: " << (usr_num/potencia)%10 << endl;
            if (turno==1) digit = (usr_num/potencia)%10;
            if ((usr_num/potencia)%10 != digit and turno%2==0 and turno!=1) winner = "A";
            if ((usr_num/potencia)%10 != digit and turno%2==1 and turno!=1) winner = "B";
        }

        xifres = 1;
        potencia = 1;  // Reset
        
        turno++;
    }

    cout << winner << endl;
}