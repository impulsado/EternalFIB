#include<iostream>
#include<string>
using namespace std;

bool vocal(char lletra) {
    if (lletra=='a' or lletra=='e' or lletra=='i' or lletra=='o' or lletra=='u') return true;
    return false;
}

bool rSquare(string word) {
    for (int i = 2; i<word.size()-1; i++) {
        if (word[i]=='r') {
            if (not vocal(word[i-1]) and word[i+1]=='r') return true;
        }
    }

    return false;
}

int main() {
    int usr_num, paraula = 0;
    string usr_word;
    while (cin >> usr_num and usr_num!=0) {
        int counter = 0;
        for (int i = 0; i<usr_num; i++) {
            cin >> usr_word;
            if (usr_word[0]=='r' and usr_word[1]=='r') counter++;
            if (rSquare(usr_word)) counter++;
        }

        // Mostrar resultat
        paraula++;
        cout << paraula << ": " << counter << endl;
    }
}