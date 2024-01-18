#include<bits/stdc++.h>
using namespace std;

int main () {
    string usr_word1;
    string usr_word2;
    int winner = 0;
    int iterations;

    cin >> usr_word1;
    cin >> usr_word2;

    if (usr_word1.length() >= usr_word2.length()) iterations = usr_word1.length(); else iterations = usr_word2.length();

    for (int i = 0; i < iterations; i++) {
        int usr_word1_int = usr_word1[i];
        int usr_word2_int = usr_word2[i];

        if (usr_word1_int > usr_word2_int) {
            winner = 1;
            break;
        }
        if (usr_word1_int < usr_word2_int) {
            winner = 2;
            break;
        }
    }

    if (winner == 0) cout << usr_word1 << " = " << usr_word2 << endl;
    if (winner == 1) cout << usr_word1 << " > " << usr_word2 << endl;
    if (winner == 2) cout << usr_word1 << " < " << usr_word2 << endl;
    
    return 0;
}