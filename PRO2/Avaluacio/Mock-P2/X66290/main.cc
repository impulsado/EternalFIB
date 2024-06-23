#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("list.hh")
#include "list.hh"
#endif
#endif

int getIdList(string s)
{
  return atoi(s.substr(1).c_str());
}

int getIdIterator(string s)
{
  return s[0]-'a';
}

void printList(List<int> &l, vector<List<int>::iterator> &vit)
{
  for (List<int>::iterator it = l.begin(); it != l.end(); it++) {
    cout << *it;
    for (int i = 0; i < int(vit.size()); i++) {
      if (vit[i] == it)
	cout << char('a'+i);
    }
    cout << ",";
  }
  for (int i = 0; i < int(vit.size()); i++) {
    if (vit[i] == l.end())
      cout << char('a'+i);
  }
  cout << endl;
}

int main()
{
  string s1, s2, s3, s4, s5, s6;
  int numlists = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numlists++;
  vector<List<int> > vl(numlists);
  int numiterators = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numiterators++;
  vector<List<int>::iterator > vit(numiterators);
  while (cin >> s1) {
    if (s1[0] == 'l') {
      List<int> &l = vl[getIdList(s1)];
      cin >> s2;
      if (s2 == ".push_front(") {
	int value;
	cin >> value >> s3;
	l.push_front(value);
      } else if (s2 == ".push_back(") {
	int value;
	cin >> value >> s3;
	l.push_back(value);
      } else if (s2 == ".insert(") {
	cin >> s3 >> s4 >> s5 >> s6;
	List<int>::iterator &it = vit[getIdIterator(s3)];
	l.insert(it, atoi(s5.c_str()));
      } else {
	cout << "WRONG ENDING " << s2 << endl;
      }
    } else if (int(s1.size()) == 1) {
      List<int>::iterator &it = vit[getIdIterator(s1)];
      string s2;
      cin >> s2;
      if (s2 == "++;") {
	it++;
      } else if (s2 == "--;") {
	it--;
      } else if (s2 == ".entangle(") {
	cin >> s3 >> s4;
	List<int>::iterator &it2 = vit[getIdIterator(s3)];
	it.entangle(it2);
      } else if (s2 == ".disentangle();") {
	it.disentangle();
      } else if (s2 == "=") {
	cin >> s3 >> s4;
	List<int> &l = vl[getIdList(s3)];
	if (s4 == ".begin();") {
	  it = l.begin();
	} else if (s4 == ".end();") {
	  it = l.end();
	}
      } else {
	cout << "WRONG ENDING " << s2 << endl;
      }
    } else if (s1 == "++") {
      cin >> s2 >> s3;
      List<int>::iterator &it = vit[getIdIterator(s2)];
      ++it;
    } else if (s1 == "--") {
      cin >> s2 >> s3;
      List<int>::iterator &it = vit[getIdIterator(s2)];
      --it;
    } else if (s1 == "cout<<") {
      cin >> s2 >> s3;
      List<int> &l = vl[getIdList(s2)];
      if (s3 == "<<endl;") {
	printList(l, vit);
      } else if (s3 == ".size()<<endl;") {
	cout << l.size() << endl;
      } else {
	cout << "WRONG ENDING " << s3 << endl;
      }
    } else if (s1 == "cout<<*") {
      cin >> s2 >> s3;
      List<int>::iterator &it = vit[getIdIterator(s2)];
      cout << *it << endl;
    } else if (s1 == "exit(0);") {
      exit(0);
    } else {
      cout << "WRONG COMMAND " << s1 << endl;
    }
  }
}
