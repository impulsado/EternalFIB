#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, usr_quant, max=0;

    while (cin >> usr_quant) {
        for (int i = 1; i<=usr_quant; i++) {
            cin >> usr_num;
            if (usr_num>=max or i==1) max=usr_num;
        }
        cout << max << endl;
        max=0; // Reset
    }
}