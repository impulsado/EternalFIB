#include <iostream>
using namespace std;

int simpleAlternatedSum(int n) {
    if (n==1) return 1;
    else if (n%2==0) return -n+simpleAlternatedSum(n-1);
    else return n+simpleAlternatedSum(n-1);
}

int main () {
    int usr_num;

    while (cin >> usr_num) cout << simpleAlternatedSum(usr_num) << endl;
}