#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num1, usr_num2, usr_num3;

    cin >> usr_num1 >> usr_num2 >> usr_num3;
    
    if (usr_num1 >= usr_num2) {
        if (usr_num1 >= usr_num3) {
            cout << usr_num1 << endl;
        } 
        else {
            cout << usr_num3 << endl;
        }
    } 
    else {
        if (usr_num2 >= usr_num3) {
            cout << usr_num2 << endl;
        } 
        else {
            cout << usr_num3 << endl;
        }
    }
    return 0;
}