#include "treeOfEvaluations.hh"

BinTree<string> prettyfy(BinTree<bool> t)
{
    if (t.empty()) return BinTree<string> ();
    return BinTree<string> (t.value()?"true":"false",
                            prettyfy(t.left()), prettyfy(t.right()));
}

int main()
{
    string format;
    getline(cin, format);
    int iformat = format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT;
    BinTree<string> t;
    t.setInputFormat(iformat);
    while (cin >> t and not t.empty()) {
        BinTree<string> r = prettyfy(treeOfEvaluations(t));
        r.setOutputFormat(iformat);
        cout << r << endl;
  	}
}
