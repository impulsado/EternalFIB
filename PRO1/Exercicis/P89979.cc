#include<bits/stdc++.h>
using namespace std;

int main () {
    bool candidate = true;
    int num_words, frase_counter = 0, winner_pos = 0;
    string prev_word="a", usr_word;

    while (cin >> num_words) {
        frase_counter++;  // Saber posicio de la frase guanyadora
        if (num_words==0 and winner_pos==0) {winner_pos = frase_counter; continue;}

        for (int i = 1; i<=num_words; i++) {
            cin >> usr_word;
            if (i==1) {prev_word = usr_word; continue;}  // tractar diferent perque no se que te prev_word
            if (usr_word>=prev_word and candidate) prev_word = usr_word; else candidate = false;
        }

        if (candidate and winner_pos==0) winner_pos = frase_counter;
        
        candidate = true;  // Reset per cada fila
    }

    if (winner_pos != 0) {
        cout << "La primera linia ordenada creixentment es la " << winner_pos << "." << endl;
    } else {
        cout << "No hi ha cap linia ordenada creixentment." << endl;
    }
}