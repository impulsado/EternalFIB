#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > cMatrix;
typedef vector< vector<int> > iMatrix;

/*
=== INFORMACIÓ PRÈVIA ===
Aquest exercici ha estat resolt fent ús de l'algoritme de suma de matrius "2D Prefix Sums".
Per a més informació:
- https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums
- https://youtu.be/Hyr3VrgJD2g?si=LBDr7S0J7iwbnaTA

=== 2D Prefix Sums (Orientat a aquest exercici) ===
Podem pensar amb l'exercici de :-::--)))--: i saber quantes cares hi ha en aquesta string.
Per a resoldre'l, fèiem servir 2 comptadors per c1 i c2 i cada cop que veiem ')' sumàvem c_total += c2.
En aquest cas, tenim una matriu, així que d'alguna manera, haurem d'anar guardant la quantitat d'ulls/ulls+nas vistos prèviament.

2D Prefix Sums permet saber la suma de nombres vistos anteriorment de la següent manera:
1. Sumar "row-1 + col-1 + (row,col)": Això es fa per saber quants números hem vist prèviament donat que els anem guardant a (row,col)
Per exemple:
2 4 3 -->     (0+0+2) (2+0+4) (6+0+3)     --> 2 6 9

2. Restar (row-1,col-1): Aquest punt és el més important. Això es fa donat que, en fer la suma dels valors vists anteriors, sempre hi ha un valor que se suma 2 vegades (row-1,col-1).
Per exemple (SENSE RESTAR):
2 4 3 -->     (0+0+2) (2+0+4) (6+0+3)     --> 2 6 9
4 7 1         (0+2+4) (6+6+7) (19+9+1)        6 19 29
! PERÒ AIXÒ NO ÉS CORRECTE !

Podem veure que en la posició (1,1) hi ha el valor 19 quan en realitat 2+4+4+7=17.
Això és pel fet que, per calcular aquests 6+6, hi ha un valor que hem sumat dues vegades (el 2).
Podem veure-ho com 6+6=(0+2+4)+(2+0+4) on el "2" és el mateix.
És per això que s'ha de restar una vegada. Això equival a fer -(row-1,col-1).

3. Ara ja només queda entendre perquè fem tot això i és que, ens servirà per portar un registre de quants ulls hem vist prèviament (la suma d'aquests).
També saber la suma d'ulls+boca vistos.
Llavors només queda tindre un comptador per fer la suma cada vegada que veiem un ')'.

# Si s'ha entès, es pot veure que aquesta suma al comptador només ens interessarà la matriu d'ulls+cara donat que aquesta ja comptindrà el nombre de cares vistes.
*/

// Demanar valors de la matriu
void askMatrix(cMatrix& matriu, int rows, int columns) {
    for (int row = 0; row<rows; row++) {
        for (int col = 0; col<columns; col++) {
            cin >> matriu[row][col];
        }
    }
}

int searchFaces(cMatrix& mOG, int rows, int columns) {
    int counter = 0;
    /*
    AQUEST ALGORITME TAMBÉ ES PODRIA IMPLEMENTAR AMB UNA ÚNICA MATRIU.
    S'hauria de fer una matriu on en cada posició hi hagués un altre vector (de tamany 2) i en la pos0 guardo els ulls vistos, i en la pos1 guardo ulls+nas vist.
    Per a fer-ho més simple, faré ús de 2 matrius.
    */
    
    // És MOLT important que aquestes matrius siguin més grans que la OG per la naturalesa del algoritme "2D Prefix Sums".
    iMatrix mUlls(rows+1,vector<int>(columns+1,0));  
    iMatrix mUllsNas(rows+1,vector<int>(columns+1,0));

    for (int row = 1; row<=rows; row++) {   // Comencem en 1,1 i no en 0,0 perquè al fer "row-1" ens podria petar donat que "-1" no es una coordenada vàlida.
        for (int col = 1; col<=columns; col++) {
            if (mOG[row-1][col-1]==':') mUlls[row][col] += 1;  // Donat que és un ull, haurem de guardar que en aquesta posició hi ha un ull.
            else if (mOG[row-1][col-1]=='-') mUllsNas[row][col] += mUlls[row-1][col-1];  // Donat que és un nas, haurem de guardar quants ulls hem vist prèviament.
            else if (mOG[row-1][col-1]==')') counter += mUllsNas[row-1][col-1];  // Donat que és una boca, ja podem començar a saber la quantitat total de cares (No faria falta una tercera matriu).

            // Ara actualitzem les matrius que guarden la quantitat d'ulls,ulls+nas vistos anteriorment
            mUlls[row][col] += mUlls[row-1][col] + mUlls[row][col-1] - mUlls[row-1][col-1];  // Saber quantitat d'Ulls vistos anteriorment
            mUllsNas[row][col] += mUllsNas[row-1][col] + mUllsNas[row][col-1] - mUllsNas[row-1][col-1];  // Saber quantitat d'UllsNas vistos anteriorment
        }
    }

    return counter;
}

int main () {
    int usr_rows, usr_cols;

    while (cin >> usr_rows >> usr_cols) {
        int counter = 0;
        
        // Demanar matriu
        cMatrix mOG(usr_rows, vector<char>(usr_cols));
        askMatrix(mOG,usr_rows,usr_cols);

        // Cas especial
        if (usr_rows<=2 or usr_cols<=2) {cout << "0" << endl; continue;}
        
        // Buscar cares
        counter = searchFaces(mOG,usr_rows,usr_cols);  // :-)

        // Mostrar resultat
        cout << counter << endl;
    }
}