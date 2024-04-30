#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<char> > cMatrix;

/*
Ample de Matriu --> (Ample-1) + 2
Alçada de Matriu --> (Alt-2)+(Alt-1)+1
*/

int ampleMatriu(int num) {
    int ample = 0;

    if (num<=1) return 1;
    else ample += ampleMatriu(num-1)+2;

    return ample;
}

int altMatriu(int num) {
    int alt = 0;

    if (num<=1) return 1;
    else alt += altMatriu(num-2)+altMatriu(num-1)+1;

    return alt;
}

void mostrarMatriu(const cMatrix& Matriu) {
    for (int i = 0; i<Matriu.size(); i++) {
        for (int j = 0; j<Matriu[0].size(); j++) {
            if (Matriu[i][j]=='\000') break;
            cout << Matriu[i][j];
        }
        cout << endl;
    }
}

void recursivitat(int num, cMatrix& Matriu) {
    // Cas Base
    if (num==1 or num==0) {Matriu[0][0] = '*'; return;}

    // Matriu num-2 <--> [AA]
    int altAA = altMatriu(num-2);
    int ampleAA = ampleMatriu(num-2);
    cMatrix MatriuAA(altAA,vector<char>(ampleAA));
    recursivitat(num-2, MatriuAA);

    // Matriu num-1 <--> [A]
    int altA = altMatriu(num-1);
    int ampleA = ampleMatriu(num-1);
    cMatrix MatriuA(altA,vector<char>(ampleA));
    recursivitat(num-1, MatriuA);

    // Matriu num
    int alt = Matriu.size();

    // Ficar '-' Principal
    Matriu[altAA][0] = '-';

    // Ficar Primera linea de '|'
    int sup, inf;
    if (num>=4) sup = altMatriu(num-4); else sup = 0;  // Fila on comença la filera. El else serveix per al cas de 2 i 3
    if (num>=3) inf = altMatriu(num-2); else inf = 0;  // Fila on acaba la filera. El else serveix per al cas 2
    for (int i = sup; i<(alt-inf); i++) {  // Faig la resta perquè només m'importa la part del mig
        Matriu[i][1] = '|';
    }

    // Ficar ' ' en primer i segona col
    for (int i = 0; i<alt; i++) {
        if (Matriu[i][0]!='-') Matriu[i][0] = ' ';
        if (Matriu[i][1]!='|') Matriu[i][1] = ' ';
    }

    // Col·locar n-2
    for (int i = 0; i<altAA; i++) {
        for (int j = 0; j<ampleAA; j++) {
            Matriu[i][j+2] = MatriuAA[i][j];
        }
    }

    // Col·locar n-1
    int supA = altAA+1;  // Determinar per quina linea de Matriu comença
    for (int i = 0; i<altA; i++) {
        for (int j = 0; j<ampleA; j++) {
            Matriu[i+supA][j+2] = MatriuA[i][j];
        }
    }
}

int main () {
    int usr_num;

    while (cin >> usr_num) {
        int ample = ampleMatriu(usr_num);
        int alt = altMatriu(usr_num);
        cMatrix Arbre(alt, vector<char>(ample));

        recursivitat(usr_num, Arbre);
        mostrarMatriu(Arbre);
        cout << endl;
    }
}