#include<iostream>
#include<vector>
using namespace std;

struct Rectangle {int x_esq, x_dre, y_baix, y_dalt;};

int relacio(const Rectangle& r1, const Rectangle& r2) {
    /*
    1 --> R1 inside R2
    2 --> R2 inside R1
    3 --> Intesecten
    4 --> R1 = R2
    0 --> Altre
    */

    // (4) Son iguals
    if ((r1.x_esq==r2.x_esq) and (r1.x_dre==r2.x_dre) and (r1.y_baix==r2.y_baix) and (r1.y_dalt==r2.y_dalt)) return 4;

    // (1) R1 inside R2
    if ((r1.x_esq>=r2.x_esq) and (r1.x_dre<=r2.x_dre) and (r1.y_baix>=r2.y_baix) and (r1.y_dalt<=r2.y_dalt)) return 1;

    // (2) R2 inside R1
    if ((r1.x_esq<=r2.x_esq) and (r1.x_dre>=r2.x_dre) and (r1.y_baix<=r2.y_baix) and (r1.y_dalt>=r2.y_dalt)) return 2;

    // (3) Intersecten
    if (r1.x_dre<=r2.x_esq or r2.x_dre<=r1.x_esq) return 0;
    if (r1.y_baix>=r2.y_dalt or r2.y_baix>=r1.y_dalt) return 0;
    return 3;
}

void llegeix(Rectangle& r) {
    cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

int main() {
    int usr_quant;

    while (cin >> usr_quant and usr_quant!=0) {
        Rectangle r1,r2;
        // Demanar Rectangles
        llegeix(r2);
        usr_quant--;
        
        bool interseccio = true;
        while (usr_quant!=0 and interseccio) {
            usr_quant--;
            r1.x_dre = r2.x_dre; r1.x_esq = r2.x_esq; r1.y_baix = r2.y_baix; r1.y_dalt = r2.y_dalt;
            
            llegeix(r2);

            int propietat = relacio(r1,r2);
            if (propietat==0) interseccio = false;
            else if (propietat==1) {  // R1 inside R2
                r2.x_dre = r1.x_dre; r2.x_esq = r1.x_esq; r2.y_baix = r1.y_baix; r2.y_dalt = r1.y_dalt;
            } else if (propietat==3) {  // Intersecten
                if (r1.x_esq > r2.x_esq) r2.x_esq = r1.x_esq;
                if (r1.x_dre < r2.x_dre) r2.x_dre = r1.x_dre;
                if (r1.y_baix > r2.y_baix) r2.y_baix = r1.y_baix;
                if (r1.y_dalt < r2.y_dalt) r2.y_dalt = r1.y_dalt;
            }
        }

        // Continuar demanant tot i que no hi hagi intersecció
        if (not interseccio) {
            cout << "interseccio buida" << endl;
            while (usr_quant!=0) {
                usr_quant--;
                llegeix(r2);
            }
        } else {
            cout << "punt inferior esquerre = (" << r2.x_esq << ", " << r2.y_baix << "); ";
            cout << "punt superior dret = (" << r2.x_dre << ", " << r2.y_dalt << ")" << endl;
        }
    }
}