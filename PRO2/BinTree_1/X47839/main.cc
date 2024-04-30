#include "maximumTree.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t1, t2;
    t1.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    t2.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t1 and not t1.empty() and cin >> t2 and not t2.empty()) {
    	BT t=maximumTree(t1, t2);
        t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << t << endl;
  	}
}
