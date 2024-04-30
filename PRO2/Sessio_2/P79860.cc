#include <iostream>
using namespace std;

void recursive(int num) {
    // Cas Base
    if (num==1) {cout << '*' << endl; return;}

    for (int i=0; i<num; i++) {cout << '*';} cout << endl;
    recursive(num-1);
    recursive(num-1);

}

int main () {
    int usr_num;
    cin >> usr_num;

    recursive(usr_num);
}