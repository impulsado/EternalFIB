#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#if __has_include("program.hh")
#include "program.hh"
#else
#if __has_include("stack.hh")
#include "stack.hh"
#endif
#endif

int getIdStack(string s)
{
  return atoi(s.substr(1).c_str());
}

int main()
{
  string s1, s2, s3, s4, s5, s6, s7;
  int numstacks = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numstacks++;
  vector<Stack<int> > s(numstacks);
  while (cin >> s1) {
    if (s1[0] == 's') {
      int idstack = getIdStack(s1);
      cin >> s2;
      if (s2 == ".push(") {
	cin >> s3 >> s4;
	int value = atoi(s3.c_str());
	s[idstack].push(value);
      } else if (s2 == ".pop();") {
	s[idstack].pop();
      } else if (s2 == ".entangle(") {
	cin >> s3 >> s4;
	int idstack2 = getIdStack(s3);
	s[idstack].entangle(s[idstack2]);
      } else if (s2 == ".disentangle();") {
	s[idstack].disentangle();
      } else {
	cout << "WRONG METHOD " << s2 << endl;
      }
    } else if (s1 == "cout<<") {
      cin >> s2 >> s3;
      int idstack = getIdStack(s2);
      if (s3 == "<<endl;") {
	cout << s[idstack] << endl;
      } else if (s3 == ".size()<<endl;") {
	cout << s[idstack].size() << endl;
      } else if (s3 == ".top()<<endl;") {
	cout << s[idstack].top() << endl;
      } else {
	cout << "WRONG ENDING " << s3 << endl;
      }
    } else if (s1 == "exit(0);") {
      exit(0);
    } else {
      cout << "WRONG COMMAND " << s1 << endl;
    }
  }
}
