#include <iostream>
using namespace std;

int main () {
    int usr_num;

    cin >> usr_num;

    for (int i = 1; i<=usr_num; i++) {cout << '*';} cout << endl;  // Superior
    
    for (int fila = 1; fila<usr_num-1; fila++) {  // Centro
        for (int j = 1; j<=fila; j++) {cout << ' ';} cout << '*';
        for (int n = 1; n<(usr_num-fila-1); n++) {cout << ' ';} cout << '*' << endl;
    }
    
    for (int m = 1; m<usr_num; m++) {cout << ' ';} cout << '*' << endl;  // Inferior
}