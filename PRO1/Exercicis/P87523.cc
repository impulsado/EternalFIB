#include<bits/stdc++.h>
using namespace std;

int main () {
    bool assigned = false, found = false;
    char prev4, prev3, prev2, prev1, usr_char;
    int counter = 0;

    while (cin >> usr_char and usr_char!='.') {
        if (not assigned) {
            if (counter==0) {prev4 = usr_char; counter++; continue;}
            else if (counter==1) {prev3 = usr_char; counter++; continue;}
            else if (counter==2) {prev2 = usr_char; counter++; continue;}
            else if (counter==3) {prev1 = usr_char; counter++; assigned = true; continue;}
        }

        if (prev4=='h' and prev3=='e' and prev2=='l' and prev1=='l' and usr_char=='o') found = true;

        prev4 = prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = usr_char;
    }

    if (found) cout << "hello" << endl; else cout << "bye" << endl;
}