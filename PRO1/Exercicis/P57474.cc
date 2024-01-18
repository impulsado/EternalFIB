#include <iostream>
using namespace std;

int factorial(int n) {
    int multi = 1;

    for (int i = 1; i<=n; i++) {
        multi = multi * i;
    }
    if (n==0) multi = 1;
    
    return multi;
}

int main()
{
    int x;
    while (cin >> x) {
        cout << factorial(x) << endl;
    }
    return 0;
}
