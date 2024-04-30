#include "numNegative.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << numNegative(t) << endl;
  	}
}