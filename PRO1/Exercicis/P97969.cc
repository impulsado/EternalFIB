#include<bits/stdc++.h>
using namespace std;

int main  () {
    int counter = 0;
    string usr_frase;

    cin >> usr_frase;

    while (true) {
        for (int i = 0; i < usr_frase.size(); i++) {
            if (usr_frase[i] == 'a') counter ++;
            if (usr_frase[i] == '.') {cout << counter << endl; return 1;}
        }
        cin >> usr_frase;
    }

    cout << counter << endl;
    return 0;
}