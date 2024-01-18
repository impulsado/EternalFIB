#include<bits/stdc++.h>
using namespace std;

int contador_de_a (char charr) {
    int counter = 0;

    if (charr == 'a') counter = 1;

    return counter;
}

int main () {
    int total = 0;
    char usr_char;

    cin >> usr_char;

    while (usr_char != '.') {
        total = total + contador_de_a(usr_char);
        cin >> usr_char;
    }
    
    cout << total << endl;
}
