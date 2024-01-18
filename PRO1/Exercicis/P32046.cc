#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, patro=0, contador=0;
    bool es_primera = false;

    while (cin >> usr_num) {
        if (es_primera==false) {patro = usr_num%1000; es_primera=true; cout << "nombres que acaben igual que " << usr_num << ":" << endl; continue;}
        if (usr_num%1000==patro) {cout << usr_num << endl; contador++;}
    }
    cout << "total: " << contador << endl;
}