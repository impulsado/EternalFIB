#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, divisor = 1, contador = 0;

    cin >> usr_num;

    if (usr_num == 0) contador = 1;
    while ((usr_num/divisor) > 0) {
        contador = contador + 1;
        divisor = divisor * 10;
    }

    cout << "The number of digits of " << usr_num << " is " << contador << "." << endl;
}