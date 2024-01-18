#include <iostream>
using namespace std;

void recursiva(int num) {
    if (num==0) cout << '0';
    else {
        for (int i = 0; i<num; i++) {
            cout << num;
            recursiva(num-1);
        }
        cout << num;
    }
}

int main () {
    int usr_num;

    while (cin >> usr_num) {
        recursiva(usr_num);
        cout << endl;
    }
}