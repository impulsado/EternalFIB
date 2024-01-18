#include <iostream>
using namespace std;

bool is_valid_date(int d, int m, int a) {
    bool is_leap, is_valid = true;

    if (a%4==0 and a%100!=0) is_leap = true;
    else if (a%100==0 and (a/100)%4==0) is_leap = true;
    else is_leap = false;

    
    if (m>12 or m<1) is_valid = false;
    if (d>31 or d<1) is_valid = false;

    if (is_valid) {
        switch (m) {
            case 1:
                if (d>31) is_valid = false;
                break;
            case 2:
                if (d>29 and is_leap) is_valid = false;
                if (d>28 and not is_leap) is_valid = false;
                break;
            case 3:
                if (d>31) is_valid = false;
                break;
            case 4:
                if (d>30) is_valid = false;
                break;
            case 5:
                if (d>31) is_valid = false;
                break;
            case 6:
                if (d>30) is_valid = false;
                break;
            case 7:
                if (d>31) is_valid = false;
                break;
            case 8:
                if (d>31) is_valid = false;
                break;
            case 9:
                if (d>30) is_valid = false;
                break;
            case 10:
                if (d>31) is_valid = false;
                break;
            case 11:
                if (d>30) is_valid = false;
                break;
            case 12:
                if (d>31) is_valid = false;
                break;
        }
    }
    
    return is_valid;
}

int main() {
    int d, m, a;
    while (cin >> d >> m >> a)
        cout << (is_valid_date(d, m, a) ? "true" : "false") << endl;
    return 0;
}
