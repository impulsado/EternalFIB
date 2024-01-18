#include <iostream>
using namespace std;

void triangle (int usr_num) {
    cout << '*' << endl;
    for (int i = 1; i<=usr_num; i++) cout << '*';
    cout << endl;
}

void repeticions (int usr_num) {
    // Cas Base
    if (usr_num==1) return;

    repeticions(usr_num-1);
    triangle(usr_num);
    repeticions(usr_num-1);
}

int main () {
    int usr_num;

    cin >> usr_num;
    if (usr_num==1) {cout << '*' << endl; return 1;}
    repeticions(usr_num);
    cout << '*' << endl;
}