#include <iostream>
#include <string>
using namespace std;


bool es_palindrom(const string& s) {
    int i, j;
    i = 0;
    j = s.length() - 1;
    bool palin = true;
    while (i < j and palin) {
        palin = (s[i] == s[j]);
        ++i;
        --j;
    }
    return palin;
}