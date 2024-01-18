#include <iostream>
#include <vector>
using namespace std;

int main () {
    int usr_quant, num;
    vector<int> vUsrNums;

    while (cin >> usr_quant) {
        if (usr_quant==0) {cout << endl; continue;}
        for (int i = 0; i<usr_quant; i++) {cin >> num; vUsrNums.push_back(num);}

        for (int i = vUsrNums.size()-1; i>0; i--) cout << vUsrNums[i] << ' ';
        cout << vUsrNums[0] << endl;
        vUsrNums.clear();
    }
}