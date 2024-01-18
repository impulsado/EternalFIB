#include<bits/stdc++.h>
using namespace std;

int main () {
    bool es_primer=true;
    int usr_num, ultim, arrel;

    while (cin >> usr_num) {
        arrel=sqrt(usr_num);

        
        cout << "divisors of " << usr_num << ": 1";

        for (int i = 2; i<=arrel and es_primer; i++) {
            if (usr_num%i==0) es_primer=false;
        }

        if (es_primer==false) {
            for (int div1 = 2; div1<=arrel; div1++) {
                ultim=div1;
                if (usr_num%div1==0) cout << " " << div1;
            }
            for (int div2 = ultim; div2>0; div2--) {
                if ((usr_num/div2)!=div2 and usr_num%div2==0) cout << " " << usr_num/div2;
            }
            cout << endl;
        } else if (usr_num!=1) {  // Era primer
            cout << " " << usr_num << endl;
        } else {
            cout << endl;
        }
    }
}