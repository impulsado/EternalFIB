#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, suma = 0, divisor = 1;

    cin >> usr_num;

    if (usr_num == 0) {cout << usr_num << " IS COOL" << endl; return 1;}

    while (usr_num/divisor>0) {
        suma = suma + ((usr_num/divisor)%10);
        divisor = divisor * 100;
    }

    if (suma%2==0) {
        cout << usr_num << " IS COOL" << endl;
    } else {
        cout << usr_num << " IS NOT COOL" << endl;
    }

    return 0;
}