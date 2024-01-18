#include<bits/stdc++.h>
using namespace std;

int main () {
    char usr_char;

    cin >> usr_char;
    
    int usr_char_int = usr_char;
    if (usr_char_int <= 90 and usr_char_int >= 65) {
        usr_char_int = usr_char_int + 32;
        char usr_char_exit = usr_char_int;
        cout << usr_char_exit << endl;
    } else {
        usr_char_int = usr_char_int - 32;
        char usr_char_exit = usr_char_int;
        cout << usr_char_exit << endl;
    }
}