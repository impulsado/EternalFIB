#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    bool is_leap;

    if (year%4==0 and year%100!=0) is_leap = true;
    else if (year%100==0 and (year/100)%4==0) is_leap = true;
    else is_leap = false;

    return is_leap;
}

int main()
{
    int a;
    while (cin >> a)
        cout << (is_leap_year(a) ? "true" : "false") << endl;

    return 0;
}
