#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_fil, usr_col, suma = 0;
    char usr_num;

    cin >> usr_fil >> usr_col;

    for (int fila = 1; fila <= usr_fil; fila++) {
        for (int col = 1; col <= usr_col; col++) {
            cin >> usr_num;
            if ((fila%2==1 and col%2==1) or (fila%2==0 and col%2==0)) suma = suma + (usr_num%'0');
        }
    }
    cout << suma << endl;
}