#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num;
    double arrel;

    while (cin >> usr_num) {
        cout.setf(ios::fixed);
        cout.precision(6);

        arrel = sqrt(usr_num);

        cout << usr_num*usr_num << " " << arrel << endl;
    }
}