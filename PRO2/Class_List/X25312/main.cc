#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("list.hh")
#include "list.hh"
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
    List<Container> l;
    List<Container>::iterator it = l.begin();
    string command;
    while (cin >> command) {
        if (command == "push_back") {
            Container c;
            cin >> c.word;
            l.push_back(c);
        } else if (command == "push_front") {
            Container c;
            cin >> c.word;
            l.push_front(c);
        } else if (command == "pop_back") {
            List<Container>::iterator itaux = l.end();
            itaux--;
            if (itaux == it) {
                cout << "Error pop_back" << endl;
                exit(0);
            }
            l.pop_back();
        } else if (command == "pop_front") {
            if (it == l.begin()) {
                cout << "Error pop_front" << endl;
                exit(0);
            }
            l.pop_front();
        } else if (command == "it++") {
            if (it == l.end()) {
                cout << "Error it++" << endl;
                exit(0);
            }
            it++;
        } else if (command == "it--") {
            if (it == l.begin()) {
                cout << "Error it--" << endl;
                exit(0);
            }
            it--;
        } else if (command == "moveSecondToLast") {
            l.moveSecondToLast();
        } else if (command == "*it") {
            if (it == l.end()) {
                cout << "Error *it" << endl;
                exit(0);
            }
            cout << (*it).word << endl;
        } else if (command == "print") {
            bool writespace = false;
            for (List<Container>::iterator it = l.begin(); not(it == l.end()); it++) {
                if (writespace) cout << " ";
                writespace = true;
                cout << (*it).word;
            }
            cout << endl;
        }
    }
}
