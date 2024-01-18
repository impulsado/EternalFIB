#include <iostream>
using namespace std;

int main () {
    int usr_num, max, digit;

    while (cin >> usr_num and usr_num!=0) {
        max = digit = 0;

        for (int i = 1; usr_num/i>0; i = i*10) max = i;
        
        while (max>0 and usr_num/max>0) {
            digit = (usr_num/max)%10;
            if (digit%2==0) cout << digit+1;
            else cout << digit;
            max = max/10;
        }

        cout << endl;
    }
}