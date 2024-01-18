#include <iostream>
using namespace std;

void invers3(int& counter, int& half) {
    string usr_paraula;

    while (cin >> usr_paraula) counter++, half = counter/2, invers3(counter,half);
    if (counter<=half and usr_paraula != "") cout << usr_paraula << endl;
    if (usr_paraula != "") counter--;
    
}

int main () {
    int counter, half;
    counter = half = 0;
    invers3(counter,half);
}