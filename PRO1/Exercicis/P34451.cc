#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_multiple, usr_num, suma=0;

    cin >> usr_multiple;

    while (cin >> usr_num) {
        if (usr_num%usr_multiple==0) suma++;
    }
    
    cout << suma << endl;
    return 0;
}