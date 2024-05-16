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

struct Container {
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
    	word = c.word;
    }
	Container &operator=(const Container &c)
	{
        if (this == &c) return *this;
    	word = c.word;
        return *this;
	}
};

int main()
{
    Stack<Container> s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            Container c;
            cin >> c.word;
            s.push(c);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "top") {
            cout << s.top().word << endl;
        } else if (command == "top2") {
            cout << s.top2().word << endl;
        }
    }
}
