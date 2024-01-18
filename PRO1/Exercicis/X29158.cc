#include <iostream>
using namespace std;

int main () {
    int counter = 0;
    char usr_char;

    while (cin >> usr_char and usr_char!='.') {
        if (usr_char>=65 and usr_char<=90) counter = counter+(usr_char-64);
        else if (usr_char>=97 and usr_char<=122) counter = counter+(usr_char-123);
    }

    cout << counter << endl;
}