#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_inici, usr_final, suma = 0;

    while (cin >> usr_inici >> usr_final) {
        for (int i = usr_inici; i<=usr_final; i++) suma = suma + (i*i*i);

        cout << "suma dels cubs entre " << usr_inici << " i " << usr_final << ": " << suma << endl;

        suma = 0;
    }
    return 0;
}