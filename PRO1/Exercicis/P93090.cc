#include <iostream>
using namespace std;

struct Fraccio {
    int num, den;   // sempre estrictament positius
};

void swap(int& a, int& b){
    int c;
    c = a; a = b; b = c;
}

int mcd(int a, int b) {
    int r;

    if (a<b) swap(a,b);
    
    r = a%b;
    while (r!=0) {
        a = b;
        b = r;
        r = a%b;
    }
    
    return b;
}

Fraccio simplifica(Fraccio numero) {
    int div_comu = 1;

    div_comu = mcd(numero.num,numero.den);
    numero.num /= div_comu;
    numero.den /= div_comu;

    return numero;
}

Fraccio suma(const Fraccio& x, const Fraccio& y) {
    Fraccio resultat;

    if (y.num==0 or y.den==0) return x;

    resultat.num = (x.num*y.den)+(x.den*y.num);
    resultat.den = (x.den)*(y.den);
    resultat = simplifica(resultat);

    return resultat;
}

int main () {
    Fraccio numero, resultat;
    int usr_num, usr_den;
    char usr_simbol = 'x', usr_barra;
    resultat.num = resultat.den = 0;

    while (usr_simbol!='=') {
        cin >> usr_num >> usr_barra >> usr_den;
        cin >> usr_simbol;
        numero.num = usr_num; numero.den = usr_den;
        
        numero = simplifica(numero);
        resultat = suma(numero,resultat);
    }

    cout << resultat.num << '/' << resultat.den << endl;
}