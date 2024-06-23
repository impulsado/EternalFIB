#include "mergeIntoFirstList.hh"
using namespace std;

void mergeIntoFirstList(list<int> &l1, list<int> l2) {
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1!=l1.end() and it2!=l2.end()) {
        if (*it1<*it2) it1++;
        else if (*it1>*it2) {
            l1.insert(it1,*it2);
            it2++;
        }
        else if (*it1==*it2) {
            l1.insert(it1,*it2);
            it1++; it2++;
        }
    }
    if (it2!=l2.end()) l1.insert(it1,it2,l2.end());
}