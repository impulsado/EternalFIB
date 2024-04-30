#include <map>
#include <string>
#include "execute.hh"

int main() {
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    map<string,int> var2val;
	string s;
  	while (cin >> t and not t.empty()) {
    	istringstream mycin(s);
        execute(var2val, t);
  	}
}
