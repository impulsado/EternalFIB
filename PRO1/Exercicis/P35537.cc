#include <iostream>
using namespace std;

bool is_increasing(int n) {
    if (n<10) return true;
    else if (((n/10)%10) > (n%10)) return false;
    else return is_increasing(n/10);
}

int main()
{
    int n;
    while (cin >> n)
        cout << (is_increasing(n) ? "true" : "false") << endl;
    return 0;
}
