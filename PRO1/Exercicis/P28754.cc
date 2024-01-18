#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, dividendo;

    cin >> usr_num;

    if (usr_num == 0) {cout << 0 << endl; return 2;}
    dividendo = usr_num;
    while (dividendo >= 2) {
        cout << (dividendo%2);
        dividendo = dividendo/2;
    }
    cout << 1 << endl;
    return 0;
}