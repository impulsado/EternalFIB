#include <iostream>
using namespace std;

void invers2(int& counter) {
    string usr_paraula;

    while (cin >> usr_paraula) invers2(counter);
    if (counter<0 and usr_paraula != "") cout << usr_paraula << endl, counter++;
    
}

int main () {
    int counter;

    cin >> counter;
    counter = counter * (-1);
    invers2(counter);
}