#include <bits/stdc++.h>
using namespace std;

int main () {
    double radians, usr_angle, seno, coseno;

    while (cin >> usr_angle) {
        cout.setf(ios::fixed);
        cout.precision(6);

        radians = (usr_angle*2*M_PI)/360;
        seno = sin(radians);
        coseno = cos(radians);

        cout << seno << " " << coseno << endl;
    }
}