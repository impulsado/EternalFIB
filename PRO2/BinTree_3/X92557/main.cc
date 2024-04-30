#include "sortTree.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        BT r=sortTree(t);
        r.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    	cout << r << endl;
  	}
}
