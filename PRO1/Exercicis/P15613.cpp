#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_temp;

    cin >> usr_temp;

    if (usr_temp < 100) {
        if (usr_temp > 0) {
            if (usr_temp > 30) cout << "it's hot" << endl;
            if (usr_temp < 10) cout << "it's cold" << endl;
            if (usr_temp <= 30 and usr_temp >= 10) cout << "it's ok" << endl;
        } else {
            cout << "it's cold" << '\n' << "water would freeze" << endl;
        }
    } else {
        cout << "it's hot" << '\n' << "water would boil" << endl;
    }
}