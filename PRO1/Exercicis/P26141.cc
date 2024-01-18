#include <typeinfo>
#include <iostream>
using namespace std;

struct Racional {
  int num, den;
};

void swap(int& a, int& b) {
  int tmp;
  tmp = a; a = b; b = tmp;
}

int mcd(int a, int b) {
    int r;
    if (a<0) a = a*(-1);  // El denominador ja l'hem tractat previament
    if (b<0) b = b*(-1);
    if (a<b) swap(a,b);

    r = a%b;
    while (r!=0) {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

Racional racional(int n, int d) {
    Racional r;
    int div_comu = 1;
    if (n==0) d = 1;
    else {
        if (d<0) d = d*(-1), n = n*(-1);  // Busquem tindre el denominador positiu.
        div_comu = mcd(n,d);
    }
        
    n /= div_comu; d /= div_comu;  // Simplificar
    r.num = n; r.den = d;  // Guardar el racional normalitzat

    return r;
}

Racional suma(Racional num1, Racional num2) {
    Racional resultat;
    int div_comu;

    resultat.num = (num1.num*num2.den)+(num1.den*num2.num);
    resultat.den = (num1.den)*(num2.den);
    
    div_comu = mcd(resultat.num,resultat.den);
    resultat.num /= div_comu;
    resultat.den /= div_comu;

    return resultat;
}

Racional resta(Racional num1, Racional num2) {
    Racional resultat;
    int div_comu;
    
    resultat.num = (num1.num*num2.den)-(num1.den*num2.num);
    resultat.den = (num1.den)*(num2.den);

    div_comu = mcd(resultat.num,resultat.den);
    resultat.num /= div_comu;
    resultat.den /= div_comu;

    return resultat;
}

Racional multiplica(Racional num1, Racional num2) {
    Racional resultat;
    int div_comu;

    resultat.num = (num1.num)*(num2.num);
    resultat.den = (num1.den)*(num2.den);

    div_comu = mcd(resultat.num,resultat.den);
    resultat.num /= div_comu;
    resultat.den /= div_comu;

    return resultat;
}

Racional divideix(Racional num1, Racional num2) {
    Racional resultat;
    int div_comu;

    resultat.num = (num1.num)*(num2.den);
    resultat.den = (num1.den)*(num2.num);

    div_comu = mcd(resultat.num,resultat.den);
    resultat.num /= div_comu;
    resultat.den /= div_comu;

    return resultat;
}

int main() {
    string usr_operacio;
    Racional resultat;
    int num, den;
    int usr_num, usr_den;

    cin >> num >> den;
    Racional r1 = racional(num, den);
    if (r1.den == 1) cout << r1.num << endl;
    else cout << r1.num << '/' << r1.den << endl;

    while (cin >> usr_operacio >> usr_num >> usr_den) {
        Racional r2 = racional(usr_num,usr_den);
        if (usr_operacio == "suma") resultat = suma(r1,r2);
        else if (usr_operacio == "resta") resultat = resta(r1,r2);
        else if (usr_operacio == "multiplica") resultat = multiplica(r1,r2);
        else if (usr_operacio == "divideix") resultat = divideix(r1,r2);

        if (resultat.den == 1) cout << resultat.num << endl;
        else cout << resultat.num << '/' << resultat.den << endl;
    }

    return 0;
}
