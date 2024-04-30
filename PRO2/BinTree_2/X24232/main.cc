#include "removeAll.hh"

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    string extension;
    while (cin >> extension) {
        cin.ignore();
        if (cin >> t and not t.empty()) {
            //BT aux = t;
            //aux.setInputOutputFormat(BT::INLINEFORMAT);
            //cout << "removeAll(" << extension << "," << aux << ")" << endl;
            BT r = removeAll(extension, t);
            r.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    		cout << r << endl;
        }
  	}
}
