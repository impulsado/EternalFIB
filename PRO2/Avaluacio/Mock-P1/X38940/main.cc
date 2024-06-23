#include "evaluate.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        bool result = evaluate(t);
        for (int repetitions = 0; repetitions < 1000; repetitions++)
            result = evaluate(t);
    	cout << (result?"true":"false") << endl;
  	}
}
