#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<string> uWord;
    int usr_num;
    string usr_word, word;

    cin >> usr_num;

    // Guardar paraules
    for (int i = 1; i<=usr_num; i++) {
        cin >> usr_word;
        uWord.push_back(usr_word);
    }

    for (int i = uWord.size()-1; i>=0; i--) {  // recorrer vector amb paraules
        word = uWord[i];
        for (int j = word.length()-1; j>=0; j--) cout << word[j];  // recorrer lletra de cada paraula
        cout << endl;
    }
}