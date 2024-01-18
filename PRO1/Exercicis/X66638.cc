#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, contador, divisor_max, resultat, digit;

    while (cin >> usr_num) {
        contador = resultat = 0;
        divisor_max = 1;
        for (int divisor = 1; usr_num/divisor>0; divisor=divisor*10) {  // Contar dígits
            contador = contador + 1;
        }
        for (int i = 1; i<contador; i++) {  // Trobar divisor més gran
            divisor_max = divisor_max * 10;
        }

        for (int divisor = divisor_max; divisor>=1; divisor=divisor/10) {  // Senars
            digit = (usr_num/divisor)%10;
            if (digit%2==0) continue;
            if (digit==0) continue;
            if (divisor==divisor_max) resultat=digit; else resultat=resultat*10, resultat=resultat+digit;
        }
        for (int divisor = divisor_max; divisor>=1; divisor=divisor/10) {  // Parells
            digit = (usr_num/divisor)%10;
            if (digit%2!=0) continue;
            if (digit==0) continue;
            if (divisor==divisor_max and resultat==0) resultat=digit; else resultat=resultat*10, resultat=resultat+digit;
        }

        cout << resultat << ' ' << resultat*2 << endl;
    }
}