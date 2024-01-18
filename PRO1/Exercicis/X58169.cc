#include <iostream>
using namespace std;

void infoSequencia(int& max, int& lpos) {
    int usr_num, counter;
    max = lpos = counter = 0;
    
    while (cin >> usr_num and usr_num!=0) {
        counter++;
        if (usr_num>=max) {max = usr_num; lpos = counter;}
    }
}

int main () {
    bool found = false;
    int usr_num, max1, pos1, pos2, counter;
    max1 = pos1 = counter = pos2 = 0;

    infoSequencia(max1, pos1);
    while (cin >> usr_num and usr_num!=0) {
        counter++;
        if (usr_num==max1 and not found) pos2 = counter, found = true;
    }

    if (not found) cout << max1 << ' ' << pos1 << " -" << endl;
    else cout << max1 << ' ' << pos1 << ' ' << pos2 << endl;
}