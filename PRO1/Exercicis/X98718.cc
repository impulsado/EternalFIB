#include<bits/stdc++.h>
using namespace std;

int main () {
    int position = 0;
    int aaa,aab,aba,abb,baa,bab,bba,bbb;
    int aaa_pos,aab_pos,aba_pos,abb_pos,baa_pos,bab_pos,bba_pos,bbb_pos;
    bool found = false;
    char usr_char,pre2,pre1;

    aaa = aab = aba = abb = baa = bab = bba = bbb = 0;
    aaa_pos = aab_pos = aba_pos = abb_pos = baa_pos = bab_pos = bba_pos = bbb_pos = 0;

    while (not found and cin >> usr_char) {
        if (position==0) {pre2 = usr_char; position++; continue;}
        else if (position==1) {pre1 = usr_char; position++; continue;}

        if (pre2=='a' and pre1=='a' and usr_char=='a') {
            aaa++;
            if (aaa_pos==0) aaa_pos = position;
            else if (position>=aaa_pos+2) aaa_pos = position;  // aixo m'assegura el cas de "aaaaa" no consideri a_1 sino a_2
            if (aaa==2 and aaa_pos>=2) {cout << "aaa" << " " << position-2 << endl; found = true; continue;}  // Aquest continue optimitza el codi
        } else if (pre2=='a' and pre1=='a' and usr_char=='b') {
            aab++;
            if (aab_pos==0) aab_pos = position;
            else if (position>=aab_pos+2) aab_pos = position;
            if (aab==2 and aab_pos>=2) {cout << "aab" << " " << position-2 << endl; found = true; continue;}
        } else if (pre2=='a' and pre1=='b' and usr_char=='a') {
            aba++;
            if (aba_pos==0) aba_pos = position;
            else if (position>=aba_pos+2) aba_pos = position;
            if (aba==2 and aba_pos>=2) {cout << "aba" << " " << position-2 << endl; found = true; continue;}
        } else if (pre2=='a' and pre1=='b' and usr_char=='b') {
            abb++;
            if (abb_pos==0) abb_pos = position;
            else if (position>=abb_pos+2) abb_pos = position;
            if (abb==2 and abb_pos>=2) {cout << "abb" << " " << position-2 << endl; found = true; continue;}
        } else if (pre2=='b' and pre1=='a' and usr_char=='a') {
            baa++;
            if (baa_pos==0) baa_pos = position;
            else if (position>=baa_pos+2) baa_pos = position;
            if (baa==2 and baa_pos>=2) {cout << "baa" << " " << position-2 << endl; found = true; continue;} 
        } else if (pre2=='b' and pre1=='a' and usr_char=='b') {
            bab++;
            if (bab_pos==0) bab_pos = position;
            else if (position>=bab_pos+2) bab_pos = position;
            if (bab==2 and bab_pos>=2) {cout << "bab" << " " << position-2 << endl; found = true; continue;} 
        } else if (pre2=='b' and pre1=='b' and usr_char=='a') {
            bba++;
            if (bba_pos==0) bba_pos = position;
            else if (position>=bba_pos+2) bba_pos = position;
            if (bba==2 and bba_pos>=2) {cout << "bba" << " " << position-2 << endl; found = true; continue;} 
        
        } else if (pre2=='b' and pre1=='b' and usr_char=='b') {
            bbb++;
            if (bbb_pos==0) bbb_pos = position;
            else if (position>=bbb_pos+2) bbb_pos = position;
            if (bbb==2 and bbb_pos>=2) {cout << "bbb" << " " << position-2 << endl; found = true; continue;} 
        
        }

        pre2 = pre1;
        pre1 = usr_char;

        position++;
    }
}