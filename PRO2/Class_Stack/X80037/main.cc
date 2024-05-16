#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("stack.hh")
#include "stack.hh"
#endif
#endif

string getLast(string s, int len)
{
    if (int(s.size()) <= len) return s;
    return s.substr(int(s.size())-len);
}

bool isSuffix(string s, string suffix)
{
    return getLast(s, suffix.size()) == suffix;
}

string removeSuffix(string s, string suffix)
{
    return s.substr(0, int(s.size())-int(suffix.size()));
}

int main()
{
    map<string, Stack<int> > id2s;
    string command;
    while (cin >> command) {
        //cout << "command " << command << endl;
        if (isSuffix(command,".push")) {
            string id = removeSuffix(command, ".push");
            int x;
            cin >> x;
            id2s[id].push(x);
        } else if (isSuffix(command,".pop")) {
            string id = removeSuffix(command, ".pop");
            id2s[id].pop();
        } else if (command == "<<") {
            string id;
            cin >> id;
            cout << id2s[id] << endl;
        } else {
            string id = command;
            cin >> command;
            if (command != "+=") {
                cerr << "Command error " << command << endl;
                exit(1);
            }
            string id2;
            cin >> id2;
            id2s[id] += id2s[id2];
        }
    }
}
