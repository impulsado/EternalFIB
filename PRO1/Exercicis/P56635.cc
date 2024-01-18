#include<iostream>
using namespace std;
struct Rectangle {int x_esq, x_dre, y_baix, y_dalt;};

void llegeix(Rectangle& r) {
    cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

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
    if (r1.x_dre<r2.x_esq or r2.x_dre<r1.x_esq) return 0;
    if (r1.y_baix>r2.y_dalt or r2.y_baix>r1.y_dalt) return 0;
    return 3;
}

int main() {
    int propietat, usr_quant;

    cin >> usr_quant;
    for (int i = 0; i<usr_quant; i++) {
        Rectangle r1, r2;
        llegeix(r1); llegeix(r2);
        propietat = relacio(r1,r2);
        if (propietat==1) cout << "el primer rectangle es interior al segon" << endl;
        else if (propietat==2) cout << "el segon rectangle es interior al primer" << endl;
        else if (propietat==3) cout << "els rectangles intersecten" << endl;
        else if (propietat==4) cout << "els rectangles son iguals" << endl;
        else cout << "els rectangles no intersecten" << endl;
    }
}