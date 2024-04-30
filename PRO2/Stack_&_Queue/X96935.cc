#include<iostream>
#include<stack>
using namespace std;

/* INFO DE STACK
#include<stack>
---
stack<type> tName;
---
.empty() --> Saber si està buit
.size() --> Quantitat d'elements
.push() --> Afegir al final
.pop() --> Treure l'últim
.top() --> Saber l'últim element
*/

int main () {
    int usr_quant, usr_num;
    bool es_palindrom = true;

    cin >> usr_quant;

    // Afegir primera meitat de valors al Stack
    int meitat = usr_quant/2;
    stack<int> sNumeros;
    for (int i = 0; i<meitat; i++) {
        cin >> usr_num;
        sNumeros.push(usr_num); 
    }

    // Comprovar els nombres restants amb el Stack
    int restants = usr_quant-meitat;
    for (int i = 0; i<restants; i++) {
        cin >> usr_num;
        
        // Saltarse el valor si aquest és la meitat exacta. Ex: "121"
        if (i==0 and usr_quant%2!=0) continue;  
        
        // Si no està buit (Perquè no peti) i el superior es igual --> Treulo = Continua sent palindrom
        if (!sNumeros.empty() and usr_num==sNumeros.top()) sNumeros.pop();
        else {es_palindrom = false; break;}
    }

    // Mostrar resultat
    if (es_palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}