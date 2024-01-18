#include <bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, max_div = 1, counter, num_pics, aux1, aux2, digit;

    while (cin >> usr_num) {
        // Reset
        counter = 1;
        num_pics = 0; 
        
        // Saber Max Div
        for (int i = 1; (usr_num/i)>0; i = i*10) {
            max_div = i;
        }  
        
        if (max_div<100) {cout << num_pics << endl; continue;}  // Menys de 3 digits
        
        while (max_div>0) {
            digit = (usr_num/max_div)%10;
            if (counter == 1) {aux1 = digit; counter++; continue;}
            else if (counter == 2) {aux2 = digit; counter++; continue;}
            
            if (aux1<aux2 and aux2>digit) num_pics++;
            aux1 = aux2;
            aux2 = digit;

            max_div = max_div/10;
        }

        cout << num_pics << endl;
    }
}