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
public:
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
    	word = c.word;
    }
    Container(const int x)
    {
        if (x != 0) {
            cerr << "Error: invalid initialization from int to string container" << endl;
            exit(1);
        }
    	word = "";
    }
	Container &operator=(const Container &c)
	{
        if (this == &c) return *this;
    	word = c.word;
        return *this;
	}
	Container &operator+=(const Container &c)
	{
    	word += c.word;
        return *this;
	}
	Container &operator=(const int x)
	{
        if (x != 0) {
            cerr << "Error: invalid assignment from int to string container" << endl;
            exit(1);
        }
    	word = "";
        return *this;
	}
};

istream &operator>>(istream &is, Container &c)
{
    is >> c.word;
    return is;
}

ostream &operator<<(ostream &os, Container c)
{
    os << c.word;
    return os;
}

Container operator+(Container c1, Container c2)
{
    Container c;
    c.word = c1.word+c2.word;
    return c;
}

void die(string message) {
    cout << message << endl;
    exit(1);
}

template <typename T>
void execute(Stack<T> s)
{
    string command;
    while (cin >> command) {
        if (command == "push") {
            T x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "top") {
            cout << s.top() << endl;
        } else if (command == "print") {
            cout << s << endl;
        } else if (command == "sum") {
            cout << s.sum() << endl;
        } else die("Error: wrong command "+command);
    }
}

int main()
{
   	string s;
    getline(cin, s);
    if (s == "int") {
        Stack<int> s;
        execute(s);
    } else if (s == "string") {
        Stack<Container> s;
        execute(s);
    } else die("Error: 'int' or 'string' not found in first line");
    
}
