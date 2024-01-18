#include<bits/stdc++.h>
using namespace std;

int main () {
    bool first = true;
    int usr_quant, usr_num, prev = 0, counter = 0;

    cin >> usr_quant;
    
    for (int i = 1; i<=usr_quant; i++ ){
        while (cin >> usr_num and usr_num != 0) {
            if(first) {prev = usr_num; first = false;}
            if(usr_num>prev) counter++;
            prev = usr_num;
        }
        cout << counter << endl;
        // Reset
        counter = 0;
        first=true;
    }
}