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
            cout << "Error: invalid initialization from int to string container" << endl;
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
            cout << "Error: invalid assignment from int to string container" << endl;
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
    exit(0);
}

template <typename T>
void execute(List<T> l)
{
    typename List<T>::iterator it1 = l.begin();
    typename List<T>::iterator it2 = l.begin();
    string command,s1,s2,s3;
    while (cin >> command) {
        if (command == "comment") {
            string s;
            getline(cin, s);
            cout << "comment: " << s << endl;
        } else if (command == "push_back") {
            T x;
            cin >> x;
            l.push_back(x);
        } else if (command == "push_front") {
            T x;
            cin >> x;
            l.push_front(x);
        } else if (command == "pop_back") {
            l.pop_back();
        } else if (command == "pop_front") {
            l.pop_front();            
        } else if (command == "it1" or command=="it2") {
            typename List<T>::iterator &it=command=="it1"?it1:it2;
            cin >> s1 >> s2;
            if (s1 != "=") die("Error: "+command+" "+s1);
            if (s2 == "begin") {
            	it = l.begin();
            } else if (s2 == "end") {
                it = l.end();
            } else if (s2 == "erase") {
                cin >> s3;
                if (s3 != command) die("Error: "+command+" = erase "+s3);
                it = l.erase(it);
            } else die ("Error: "+command+" = "+s2);
        } else if (command == "it1++") {
            it1++;
        } else if (command == "it2++") {
            it2++;
        } else if (command == "it1--") {
            it1--;
        } else if (command == "it2--") {
            it2--;
        } else if (command == "++it1") {
            ++it1;
        } else if (command == "++it2") {
            ++it2;
        } else if (command == "--it1") {
            --it1;
        } else if (command == "--it2") {
            --it2;
        } else if (command == "*it1" or command == "*it2") {
            typename List<T>::iterator &it=command=="*it1"?it1:it2;
            cin >> s1;
            if (s1 != "=") die("Error: *it "+s1);
            T x;
            cin >> x;
            *it = x;
        } else if (command == "insert") {
            cin >> s1;
            if (s1 != "it1" and s1 != "it2") die("Error: insert "+s1);
            typename List<T>::iterator &it=s1=="it1"?it1:it2;
            T x;
            cin >> x;
			l.insert(it,x);
        } else if (command == "cout") {
            cin >> s1 >> s2;
            if (s1 != "<<") die("Error: cout "+s1);
            if (s2 == "*it1") {
            	cout << *it1 << endl;
            } else if (s2 == "*it2") {
            	cout << *it2 << endl;
            } else if (s2 == "l") {
                bool writespace = false;
                for (typename List<T>::iterator it = l.begin(); it != l.end(); it++) {
                    if (writespace) cout << " ";
                    writespace = true;
                    if (it == it1) cout << "(";
                    if (it == it2) cout << "[";
                    cout << *it;
                    if (it == it2) cout << "]";
                    if (it == it1) cout << ")";
                }
                if (it1 == l.end() or it2==l.end()) {
                    if (writespace) cout << " ";
                    if (it1 == l.end()) cout << "(";
                    if (it2 == l.end()) cout << "[]";
                    if (it1 == l.end()) cout << ")";
                }
                cout << endl;
                //cout << l << endl;
            } else die("Error: cout << "+s2);
        } else die("Error: wrong command "+command);
    }
}

int main()
{
    List<Container> l;
    execute(l);
}


