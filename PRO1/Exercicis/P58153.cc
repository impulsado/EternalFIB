#include<bits/stdc++.h>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(10);

    int usr_num1, usr_num2;
    double resultat;

    while (cin >> usr_num1 >> usr_num2) {
        resultat = 0.0;
        for (int i = usr_num2+1; i<=usr_num1; i++) resultat = resultat + (1.0/double(i));
        cout << resultat << endl;
    }
 
}