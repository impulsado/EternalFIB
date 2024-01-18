#include <iostream>
using namespace std;

int main () {
    bool found = false;
    int usr_num, max, counter, digit;

    while (cin >> usr_num) {
        counter = max = 0;  // Reset
        for (int i = 1; usr_num/i>0; i = i*10) max = i;
        
        while (max>0 and (usr_num/max)>0) {
            digit = (usr_num/max)%10;
            if (digit%2==1) counter = counter + digit;
            max = max/10;
        }

        if (counter%2==0 and not found) found = true, cout << usr_num << endl;
    }

    if (not found) cout << "no impar-par" << endl;
}