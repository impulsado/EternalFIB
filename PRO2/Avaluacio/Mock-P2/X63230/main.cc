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
#if __has_include("queue.hh")
#include "queue.hh"
#endif
#endif

int getIdQueue(string s)
{
  return atoi(s.substr(1).c_str());
}

void die(string message) {
    cout << message << endl;
    exit(1);
}

int main()
{
  string s1, s2, s3, s4, s5, s6, s7;
  int numqueues = 1;
  cin >> s1;
  for (cin >> s1 >> s2; s2 != ";"; cin >> s1 >> s2) numqueues++;
  vector<Queue<int> > q(numqueues);
  while (cin >> s1) {
    if (s1[0] == 'q') {
      int idqueue = getIdQueue(s1);
      cin >> s2;
      if (s2 == ".push(") {
          cin >> s3 >> s4;
          int value = atoi(s3.c_str());
          q[idqueue].push(value);
      } else if (s2 == ".pop();") {
          q[idqueue].pop();
      } else {
          cout << "WRONG METHOD " << s2 << endl;
      }
    } else if (s1 == "cout<<") {
      cin >> s2 >> s3;
      int idqueue = getIdQueue(s2);
      if (s3 == "<<endl;") {
	cout << q[idqueue] << endl;
      } else if (s3 == ".size()<<endl;") {
	cout << q[idqueue].size() << endl;
      } else if (s3 == ".front()<<endl;") {
	cout << q[idqueue].front() << endl;
      } else if (s3 == ".getLast()<<endl;") {
	cout << q[idqueue].getLast() << endl;
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
