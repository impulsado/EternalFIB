#include<bits/stdc++.h>
using namespace std;

int main () {
    bool is_set = false;
    int happy_counter, sad_counter, general_counter;
    char usr_char, prev2='x', prev1='x';

    happy_counter = sad_counter = general_counter = 0;

    while (cin >> usr_char) {
        if (not is_set) {
            if (general_counter==0) {prev2 = usr_char; general_counter++; continue;}
            else if (general_counter==1) {prev1 = usr_char; is_set = true; general_counter++; continue;}
        }

        if (prev2==':' and prev1=='-' and usr_char==')') happy_counter++;
        else if (prev2=='(' and prev1=='-' and usr_char==':') happy_counter++;

        if (prev2==':' and prev1=='-' and usr_char=='(') sad_counter++;
        else if (prev2==')' and prev1=='-' and usr_char==':') sad_counter++;

        
        prev2 = prev1; 
        prev1 = usr_char;
    }
    
    cout << happy_counter << " " << sad_counter << endl;
}