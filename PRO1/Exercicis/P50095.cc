#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n<=1) return false;
    if (n==2 or n==3) return true;
    if (n%2==0 or n%3==0) return false;
    
    for (int i = 5; i<=sqrt(n); i = i+2) {
        if (n%i==0) return false;
    }
    return true;
}

int main () {
    bool found;
    int usr_num, num1;

    while (cin >> usr_num) {
        // Reset
        num1 = usr_num;
        found = false;

        if (not isPrime(usr_num)) return 0; else {
            while (not found) {
                num1++;
                if (isPrime(num1)) found = true;
            }
            cout << num1 << endl;
        }
    }
}