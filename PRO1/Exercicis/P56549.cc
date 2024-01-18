#include <iostream>
using namespace std;

void toBinary (int n) {
    if (n<2) cout << n;
    else {
        toBinary(n/2);
        cout << n%2;
    }
}

void toOctal (int n) {
    if (n<8) cout << n;
    else {
        toOctal(n/8);
        cout << n%8;
    }
}

void toHexa (int n) {
    if (n<16) {
        if (n<10) cout << n;
        else if (n==10) cout << 'A';
        else if (n==11) cout << 'B';
        else if (n==12) cout << 'C';
        else if (n==13) cout << 'D';
        else if (n==14) cout << 'E';
        else if (n==15) cout << 'F';
    }
    else {
        toHexa(n/16);
        if (n%16<10) cout << n%16;
        else if (n%16==10) cout << 'A';
        else if (n%16==11) cout << 'B';
        else if (n%16==12) cout << 'C';
        else if (n%16==13) cout << 'D';
        else if (n%16==14) cout << 'E';
        else if (n%16==15) cout << 'F';
    }
}

int main() {
    int usr_num;
    while (cin >> usr_num) {
        cout << usr_num << " = ";
        toBinary(usr_num);
        cout << ", ";
        toOctal(usr_num);
        cout << ", ";
        toHexa(usr_num);
        cout << endl;
    }
    return 0;
}