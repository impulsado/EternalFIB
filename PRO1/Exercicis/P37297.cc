#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, suma = 0;

    cin >> usr_num; 

    suma = suma + (usr_num%10);  // Últim
    suma = suma + ((usr_num/10)%10);  // Penúltim
    suma = suma + ((usr_num/100)%10);  // Antepenúltim

    cout << suma << endl;
}