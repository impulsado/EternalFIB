#include <iostream>
#include <vector>
using namespace std;

long long power(long long base, long long exp, long long m) {
    long long result = 1;
    while (exp>0) {
        if (exp%2 == 1) result = (base*result)%m;
        base = (base*base)%m;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n,exp,m;

    while (cin >> n >> exp >> m) {
        cout << power(n,exp,m) << endl;
    }
}