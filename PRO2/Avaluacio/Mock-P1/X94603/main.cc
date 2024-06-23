// Add or remove includes
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <cstdlib>

using namespace std;

#include "mergeIntoFirstList.hh"

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

struct Test {
    list<int> l1, l2;
};

list<int> readList(string line)
{
    istringstream mycin(line);
    list<int> l;
    int x;
    while (mycin >> x)
        l.push_back(x);
    return l;
}

void writeList(list<int> l)
{
    bool writespace = false;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        if (writespace) cout << " ";
        writespace = true;
        cout << *it;
    }
    cout << endl;
}

#endif


int main()  {
    /*
    string line1, line2;
    while (getline(cin, line1) and getline(cin, line2)) {
        list<int> l1 = readList(line1);
        list<int> l2 = readList(line2);
        mergeIntoFirstList(l1, l2);
        writeList(l1);
    }
    */
    
    vector<Test> test;
    string line1, line2;
    while (getline(cin, line1) and getline(cin, line2)) {
        Test t;
        t.l1 = readList(line1);
        t.l2 = readList(line2);
        test.push_back(t);
    }
    for (int i=0;i<int(test.size());i++) {
        list<int> &l1 = test[i].l1;
        list<int> &l2 = test[i].l2;
        mergeIntoFirstList(l1, l2);
        writeList(l1);
    }
    
}
