#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("queue.hh")
#include "queue.hh"
#endif
#endif

int main()
{
    Queue<string> q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            string x;
            cin >> x;
            q.push(x);
        } else if (command == "push_front") {
            string x;
            cin >> x;
            q.push_front(x);
        } else if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else {
            cout << "WRONG COMMAND" << endl;
        }
    }
}
