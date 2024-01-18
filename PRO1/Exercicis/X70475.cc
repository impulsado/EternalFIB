#include<bits/stdc++.h>
using namespace std;

int main () {
    int sad_counter, happy_counter;
    char usr_char, prev='x', mouth_type='x';
    bool face_started;

    sad_counter = happy_counter = 0;
    face_started = false;

    while (cin >> usr_char) {
        if (usr_char==':' and prev=='-' and mouth_type==')') sad_counter++;
        else if (face_started and prev=='-' and usr_char==')') {happy_counter++; face_started = false;}

        if (usr_char==':' and prev=='-' and mouth_type=='(') happy_counter++;
        else if (face_started and prev=='-' and usr_char=='(') {sad_counter++; face_started = false;}

        if (usr_char==')') {mouth_type = ')'; face_started = false;}
        else if (usr_char=='(') {mouth_type = '('; face_started = false;}
        else if (usr_char==':') {face_started = true; mouth_type = 'x';}

        prev = usr_char;
    }

    cout << happy_counter << " " << sad_counter << endl;
}