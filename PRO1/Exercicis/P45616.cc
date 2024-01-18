#include <iostream>
#include <typeinfo>
using namespace std;

struct Clock {
    int h;
    int m;
    int s;
};

Clock midnight() {
    Clock r;

    r.h = 0;
    r.m = 0;
    r.s = 0;

    return r;
}

void increase(Clock& r) {
    r.s++;
    if (r.s==60) {
        r.s = 0; r.m++;
        if (r.m==60) {
            r.m = 0; r.h++;
            if (r.h==24) {
                r.h = 0;
            }
        }
    }
}

void print(const Clock& r) {
    if (r.h<10) cout << '0' << r.h << ':';
    else cout << r.h << ':';
    if (r.m<10) cout << '0' << r.m << ':';
    else cout << r.m << ':';
    if (r.s<10)cout << '0' << r.s << endl;
    else cout << r.s << endl;
}

int main() {
    Clock r = midnight();
    for (int i = 0; i <= 25 * 60 * 60; ++i) {
        print(r);
        increase(r);
    }
    return 0;
}
