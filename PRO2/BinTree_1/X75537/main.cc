#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "searchInBST.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
	cin >> t;
    int x;
    while (cin >> x) {
		if (searchInBST(t, x)) cout << "Exists" << endl;
        else cout << "Does not exist" << endl;
    }
}
