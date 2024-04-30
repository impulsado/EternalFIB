#include <map>
#include <iostream>
using namespace std;

void show_word_counter(map<string,int>& dictionary, string usr_word) {
    // .find() retorna un iterator en la posicio d'on a trobat l'element amb key 'usr_word'
    // si no el troba, el iterator el retorna al final del map.
    if (dictionary.find(usr_word)!=dictionary.end()) cout << dictionary[usr_word] << endl;
    else cout << '0' << endl;
}

int main () {
    char usr_op;
    string usr_word;
    map<string,int> dictionary;

    while (cin >> usr_op >> usr_word) {
        if (usr_op == 'a') dictionary[usr_word]++;  // Això ho crea si no existeix i incrementa. Si existeix unicament incrementa
        else if (usr_op == 'f') show_word_counter(dictionary,usr_word);
    }
}