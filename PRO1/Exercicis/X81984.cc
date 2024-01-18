#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num1, usr_num2, usr_num3;
    float av1, av2, av3;

    av1 = av2 = av3 = 0.0;
    
    cin >> usr_num1 >> usr_num2 >> usr_num3;

    av1 = (usr_num1+usr_num2)/2.0;
    av2 = (usr_num1+usr_num3)/2.0;
    av3 = (usr_num2+usr_num3)/2.0;

    if (usr_num1 == av3) {
        cout << "YES" << endl;
    } else if (usr_num2 == av2) {
        cout << "YES" << endl;
    } else if (usr_num3 == av1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}