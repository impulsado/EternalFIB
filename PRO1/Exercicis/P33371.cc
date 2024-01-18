#include <iostream>
using namespace std;

char codificat(char usr_char, int usr_pos) {
    usr_pos = usr_pos%26;
    if (usr_char+usr_pos>122) usr_char = usr_char+(usr_pos-1)-25;
    else usr_char = usr_char+usr_pos;
    return usr_char-32;
}

int main () {
    int usr_pos;
    char usr_char;

    while (cin >> usr_pos) {
        while (cin >> usr_char and usr_char != '.') {
            if (usr_char<=122 and usr_char>=97) cout << codificat(usr_char, usr_pos);
            else if (usr_char == '_') cout << ' ';
            else cout << usr_char; 
        }
        cout << endl;
    }
}