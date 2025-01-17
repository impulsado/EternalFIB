#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
    string usr_word;
    set<string> llista;
    int counter = 0;
    bool increment = false;
    set<string>::iterator it;


    while (cin >> usr_word and usr_word != "END") {
        counter++;

        llista.insert(usr_word);
        if (counter == 1) {
            it = llista.begin();
            cout << usr_word << endl;
            continue;
        }

        if (usr_word < *it) {
            if (counter%2 == 0) it = prev(it);
        }
        else {
            if (counter%2 != 0) it = next(it);
        }
        
        cout << *it << endl;
    }
}