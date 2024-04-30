#include <map>
#include <string>
#include "evaluate.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
	string s;
  	while (getline(cin, s) and cin >> t and not t.empty()) {
    	istringstream mycin(s);
    	map<string,int> variable2value;
    	string variable;
    	int value;
    	while (mycin >> variable >> value) variable2value[variable] = value;
        //cin >> t;
        if (format=="INLINEFORMAT") getline(cin, s);
    	cout << evaluate(variable2value, t) << endl;
  	}
}
