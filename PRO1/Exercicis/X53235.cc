#include <iostream>
using namespace std;

int mcd(int a, int b) {
    int temp;
    while (b!=0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//pre: a i b són no-negatius. A més a > 0 o b > 0
//post: calcula la parella de coeficients divertits x i y definits anteriorment.
//      Es compleix xa + yb = mcd(a,b)
void funny_coeffs(int a, int b, int& x, int& y) {
    // Cas base
    if (b==0) {
        x = 1; y = 0;
        return;
    }
    int x1,y1;
    funny_coeffs(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
}

int main() {
    int a,b;
    int x,y,d;

    while (cin >> a >> b) {
        d = mcd(a,b);
        funny_coeffs(a,b,x,y);
        cout << x << ' ' << y << ' ' << d << endl;
    }
}