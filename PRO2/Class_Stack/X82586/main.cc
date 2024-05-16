#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("stack.hh")
#include "stack.hh"
#endif
#endif

const int MAXSIZE = 200000;

struct Container {
    char s[MAXSIZE];
};

int main()
{
    Stack<Container> s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            Container c;
            string word;
            cin >> word;
            strcpy(c.s, word.c_str());
            s.push(c);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "top") {
            cout << string(s.top().s) << endl;
        } else if (command == "swap2Topmost") {
            s.swap2Topmost();
        }
    }
}
