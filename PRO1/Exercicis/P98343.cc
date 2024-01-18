#include<iostream>
#include<string>
#include<vector>
using namespace std;

const vector<string> numeros = {"zero", "un", "dos", "tres", "quatre", "cinc", "sis", "set", "vuit", "nou"};
const vector<string> deus = {"deu", "once", "dotze", "tretze", "catorze", "quinze", "setze", "disset", "divuit", "dinou"};
const vector<string> especials = {"", "", "vint", "trenta", "quaranta", "cinquanta", "seixanta", "setanta", "vuitanta", "noranta"};

string numToWord(long usr_num) {
    int digit;
    int lsd;  // less significant digit

    if (usr_num<10) {  // 0,1,2,3...
        cout << " " << numeros[usr_num];
    } else if (usr_num<20) {  // 11,12,13...
        digit = usr_num-10;
        cout << " " << deus[digit];
    } else if (usr_num<30) {  // 20,21,22,...
        digit = usr_num/10;
        lsd = usr_num%10;

        if (lsd!=0) {
            cout << " " << especials[digit] << "-i-" << numeros[lsd];
        } else cout << " " << especials[digit];  // 20

    } else if (usr_num<100) {  //30,41,91...
        digit = usr_num/10;
        lsd = usr_num%10;

        if (lsd!=0) {
            cout << " " << especials[digit] << "-" << numeros[lsd];
        } else cout << " " << especials[digit];

    } else if (usr_num<1000) {  // 999
        digit = usr_num/100;

        if (digit==1) {
            if (usr_num%100!=0) {
                cout << " " << "cent" << numToWord(usr_num%100);
            } else {
                cout << " " << "cent";
            }
        } else {
            if (usr_num%100!=0) {
                cout << " " << numeros[digit] << " " << "cents" << numToWord(usr_num%100);
            } else {
                cout << " " << numeros[digit] << " " << "cents";
            }
        }

    } else if (usr_num<10000) {  // 9.999
        digit = usr_num/1000;

        if (digit==1) {
            if (usr_num%1000!=0) {
                cout << " " << "mil" << numToWord(usr_num%1000);
            } else {
                cout << " " << "mil";
            }
        } else {
            if (usr_num%1000!=0) {
                cout << " " << numeros[digit] << " " << "mil" << numToWord(usr_num%1000);
            } else {
                cout << " " << numeros[digit] << " " << "mil"; 
            }
        }
    } else if (usr_num<100000) {  // 99.999
        digit = usr_num/1000;

        cout << " " << numToWord(digit) << " " << "mil" << numToWord(usr_num%1000);
    } else if (usr_num<1000000) { // 999.999
        digit = usr_num/10000;

        cout << " " << numToWord(digit) << " " << "mil" << numToWord(usr_num%1000);
    } else if (usr_num<10000000) { // 9.999.999
        digit = usr_num/1000000;

        if (digit==1) {
            if (usr_num%1000000!=0) {
                cout << " " << "milio" << numToWord(usr_num%1000000);
            } else {
                cout << " " << "milio";
            }
        } else {
            if (usr_num%1000000!=0) {
                cout << " " << numeros[digit] << " " << "milions" << numToWord(usr_num%1000000);
            } else {
                cout << " " << numeros[digit] << " " << "milions"; 
            }
        }
    } else if (usr_num<100000000) {  // 99.999.999
        digit = usr_num/1000000;

        cout << " " << numToWord(digit) << " " << "mil" << numToWord(usr_num%1000000);
    } else if (usr_num<1000000000) {  // 999.999.999

    }
    

    return "";
}

int main() {
    long usr_num;

    while (cin >> usr_num) {
        cout << usr_num << ":" << numToWord(usr_num) << '.' << endl;
    }
}