#include <list>

using namespace std;

#include "longestLeftmostPath.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	list<int> l;
        //for (int steps = 0; steps < 10; steps++)
            l = longestLeftmostPath(t);
        bool writespace = false;
        cout << "[";
        for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
            if (writespace) cout << ",";
            writespace = true;
            cout << *it;
        }
        cout << "]" << endl;
	}
}
