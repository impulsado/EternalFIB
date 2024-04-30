#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos) {
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    while (it1!=uno.end()) {
        bool found = false;
        while (it2!=dos.end()) {
            int num1 = *it1; int num2 = *it2;
            if (num1==num2) {found = true; break;}
            if (num1<num2) break;
            it2++;
        }
        if (not found) it1 = uno.erase(it1);
        else it1++;
    }
}
/*
int main() {
    list<int> L1, L2;
    L1 = {-7,1,5,12};
    L2 = {1,3,4,5};
    inter(L1,L2);
}
*/
