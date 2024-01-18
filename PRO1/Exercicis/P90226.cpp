#include<bits/stdc++.h>
using namespace std;

int main () {
    string usr_string1, usr_string2;
    int max_iterations;

    cin >> usr_string1;
    cin >> usr_string2;

    char arr_string1[usr_string1.length() + 1];
    char arr_string2[usr_string1.length() + 1];

    if (usr_string1.length() == usr_string2.length()) max_iterations = usr_string1.length(); 
    if (usr_string1.length() > usr_string2.length()) max_iterations = usr_string1.length(); else max_iterations = usr_string2.length();

    for (int i = 0; i <= max_iterations; i++){
        int usr_char1 = arr_string1[i];
        int usr_char2 = arr_string2[i];

        // AQUÍ NO ESTIC FENT BÉ LES COMPROVACIONS
        if ((usr_char1 == usr_char2) and i == max_iterations) cout << usr_string1 << " = " << usr_string2 << endl;
        if (usr_char1 > usr_char2) cout << usr_string1 << " < " << usr_string2 << endl; else cout << usr_string2 << " < " << usr_string1 << endl;
    }

}