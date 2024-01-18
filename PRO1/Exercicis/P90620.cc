#include<bits/stdc++.h>
using namespace std;

int main () {
    int usr_num, prev=0, pic=0, max=0, counter=0;

    while (cin >> usr_num and usr_num!=0) {
        if (counter==0) {prev=usr_num; counter++; continue;}
        if (counter==1) {pic=usr_num; counter++; continue;}

        //cout << "PREV: " << prev << " PIC: " << pic << " ACT: " << usr_num << endl;
        if (prev<pic and pic>usr_num and max<pic) max = pic;
        prev=pic;
        pic=usr_num; 
    }

    if (max>3143) cout << "YES" << endl; else cout << "NO" << endl;
}