#include<bits/stdc++.h>
using namespace std;

int main () {
    int position, counter, a_counter, b_counter, c_counter, d_counter;
    char usr_char, winner='x';
    bool found;

    found = false;
    position = counter = a_counter = b_counter = c_counter = d_counter = 0;

    while (not found and cin >> usr_char) {
        if (usr_char=='a') a_counter++;
        else if (usr_char=='b') b_counter++;
        else if (usr_char=='c') c_counter++;
        else d_counter++;
        
        if (a_counter==2) {winner = 'a'; position = counter; found = true;}
        else if (b_counter==2) {winner = 'b'; position = counter; found = true;}
        else if (c_counter==2) {winner = 'c'; position = counter; found = true;}
        else if (d_counter==2) {winner = 'd'; position = counter; found = true;}

        counter++;
    }

    cout << winner << " " << position << endl;
}