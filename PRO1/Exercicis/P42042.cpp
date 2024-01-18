#include<bits/stdc++.h>
using namespace std;

int main () {
    char usr_char;
    string usr_vocal;

    cin >> usr_char;
    
    int usr_char_int = usr_char;
    if (usr_char_int <= 90 and usr_char_int >= 65) {
        if (usr_char_int == 65 or usr_char_int == 69 or usr_char_int == 73 or usr_char_int == 79 or usr_char_int == 85) usr_vocal = "vowel"; else usr_vocal = "consonant";
        cout << "uppercase" << '\n' << usr_vocal << endl;
    } else {
        if (usr_char_int == 97 or usr_char_int == 101 or usr_char_int == 105 or usr_char_int == 111 or usr_char_int == 117) usr_vocal = "vowel"; else usr_vocal = "consonant";
        cout << "lowercase" << '\n' << usr_vocal << endl;
    }
}