#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, dividendo, cociente;

    cin >> usr_num;

    // Tractar cassos especials
    if (usr_num == 0) {cout << 0 << endl; return 1;}
    if (usr_num == 10) {cout << "A" << endl; return 2;}
    if (usr_num == 11) {cout << "B" << endl; return 2;}
    if (usr_num == 12) {cout << "C" << endl; return 2;}
    if (usr_num == 13) {cout << "D" << endl; return 2;}
    if (usr_num == 14) {cout << "E" << endl; return 2;}
    if (usr_num == 15) {cout << "F" << endl; return 2;}
    if (usr_num == 16) {cout << "01" << endl; return 3;}

    dividendo = usr_num;
    while (dividendo >= 16) {
        cociente = dividendo%16;

        if (cociente == 15) {
            cout << "F";
        } else if (cociente == 14) {
            cout << "E";
        } else if (cociente == 13) {
            cout << "D";
        } else if (cociente == 12) {
            cout << "C";
        } else if (cociente == 11) {
            cout << "B";
        } else if (cociente == 10) {
            cout << "A";
        } else {
            cout << cociente;
        }

        dividendo = dividendo/16;
    }
    
    if (dividendo != 0) cout << dividendo;
    cout << endl;
    return 0;
}