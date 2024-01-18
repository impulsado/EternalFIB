#include <bits/stdc++.h>
using namespace std;

int main () {
    int c_counter, d_counter, prov_counter;
    bool a_vista, b_vista_c, b_vista_d, c_vista, d_vista;
    char usr_char;

    c_counter = d_counter = prov_counter = 0;
    a_vista = b_vista_c = b_vista_d = c_vista = false;

    while (cin >> usr_char) {
        if (usr_char == 'a') {
            a_vista = true; b_vista_c = false;  // c
            if (not b_vista_d) {  // d
                d_counter = d_counter + prov_counter;
                b_vista_d = false;
                prov_counter = 0;
            }
            continue;
        }
        else if (usr_char == 'b') {
            // c
            b_vista_c = true; 
            // d 
            b_vista_d = true; 
            prov_counter = 0; 
            continue;
        }
        else if (usr_char == 'c') {  // c
            if (a_vista and not b_vista_c) {c_counter++; continue;}
        }
        else if (usr_char == 'd') {  // d
            b_vista_d = false;
            prov_counter++;
            continue;
        }
    }

    cout << c_counter << " " << d_counter << endl;
}

/*
        if (usr_char == 'a') {a_vista = true; b_vista_c = false; continue;}
        else if (a_vista and usr_char == 'b') {b_vista_c = true; continue;}
        else if (a_vista and not b_vista_c and usr_char == 'c') {c_counter++; continue;}
*/