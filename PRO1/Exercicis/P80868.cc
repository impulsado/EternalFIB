#include<iostream>
using namespace std;

int nombre_digits(int n) {
    if (n==0) return 1;  // Cas Especial
    
    int counter = 0;
    for (int i = 1; (n/i)>=1; i*=10) counter++;
    return counter;
}

void recursiva(int num, int quantitat, int digits, int total) {
    if (quantitat==1) {
        // NUM
        cout << num;
        // PUNTS
        int punts = total-(2*digits);
        for (int i = 0; i<punts; i++) cout << '.';
        // NUM
        cout << num << endl;
    } else {
        recursiva(num,quantitat-1,digits,total);
        
        // NUM
        cout << num;
        for (int i = 1; i<quantitat; i++) cout << '-' << num;
        // PUNTS
        int punts = total-2*((digits*quantitat)+(quantitat-1));
        for (int i = 0; i<punts; i++) cout << '.';
        // NUM
        for (int i = 1; i<quantitat; i++) cout << num << '-';
        cout << num << endl;
    }
}

int main() {
    int usr_num, usr_quant;
    cin >> usr_num >> usr_quant;
    
    int digits = nombre_digits(usr_num);
    int total = 2*(digits*usr_quant+usr_quant-1)+1;
    recursiva(usr_num, usr_quant, digits, total);
}