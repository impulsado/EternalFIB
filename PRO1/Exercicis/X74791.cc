#include <iostream>
using namespace std;

int main () {
    int usr_num, max = 0, counter = 0;

    while (cin >> usr_num) {
        if (usr_num == -1) {cout << "total: " << counter << endl; return 0;}
        for (int i = 1; usr_num/i>0; i = i*10) max = i;
        if (usr_num/max == usr_num%10) cout << usr_num << endl, counter++;
    }
}