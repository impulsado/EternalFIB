#include <iostream>
using namespace std;

void repeticions (int usr_num, int counter) {
    // Cas Base
    if (counter==1) {cout << '*' << endl; return;}

    repeticions(usr_num, counter-1);
    repeticions(usr_num, counter-1);
    for (int i = 1; i<=counter; i++) cout << '*';
    cout << endl;
}

int main () {
    int usr_num, counter;

    cin >> usr_num;
    counter = usr_num;
    if (usr_num==1) {cout << '*' << endl; return 1;}
    
    repeticions(usr_num, counter);
}