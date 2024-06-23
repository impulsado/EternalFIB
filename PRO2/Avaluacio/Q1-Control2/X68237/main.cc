#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
#include <vector>

#include "BinTree.hh"

int getIdVar(string s)
{
 return atoi(s.substr(1).c_str());
}

int getSize(const BinTree<int>& t) {
    if (t.empty()) return 0;

    int left = getSize(t.left());
    int right = getSize(t.right());
    return left+right+1;
}

int getSum(const BinTree<int>& t) {
    if (t.empty()) return 0;

    int left = getSum(t.left());
    int right = getSum(t.right());
    return left+right+t.value();
}

int main()
{
 string s1, s2, s3, s4, s5, s6, s7;
 int numvars;
 cin >> s1 >> numvars >> s2;
 // Ficar Arbres buits
 vector<BinTree<int>> registre(numvars);
 for (int i = 0; i<numvars; i++) registre[i] = BinTree<int>();

 while (cin >> s1 >> s2) {
  if (s1[0] == 't') {
   int idvar = getIdVar(s1);
   if (s2 == "=BinTree(") {
    int value;
    cin >> value >> s3 >> s4 >> s5 >> s6 >> s7;
    int idvar1 = getIdVar(s4);
    int idvar2 = getIdVar(s6);
    registre[idvar] = BinTree<int>(value, registre[idvar1], registre[idvar2]);

   } else if (s2 == "=") {
    cin >> s3 >> s4;
    int idvar1 = getIdVar(s3);
    if (s4 == ".left();") {
     registre[idvar] = registre[idvar1].left();
    } else {
     registre[idvar] = registre[idvar1].right();
    }
   }
  } else if (s1 == "cout<<") {
   int idvar = getIdVar(s2);
   cin >> s3;
   registre[idvar].setOutputFormat(BinTree<int>::INLINEFORMAT);
   cout << registre[idvar] << endl;
  } else if (s1 == "cout<<size(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   cout << getSize(registre[idvar]) << endl;
  } else if (s1 == "cout<<sum(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   cout << getSum(registre[idvar]) << endl;
  }
 }
}