#include<iostream>
#include<vector>
using namespace std;

int recursivitat(int num1, int num2, char op, bool op_seen) {
    char usr_char;

    // NUM1
    cin >> usr_char;
    if (usr_char=='(' and not op_seen) num1 = recursivitat(num1, num2, op, false);
    else if (48<=usr_char and usr_char<=57 and not op_seen) num1 = usr_char-'0';

    // OPERACIÓ
    cin >> op; op_seen = true;

    // NUM2
    cin >> usr_char;
    if (usr_char=='(' and op_seen) num2 = recursivitat(num1, num2, op, false);
    else if (48<=usr_char and usr_char<=57 and op_seen) num2 = usr_char-'0';

    // RESULTAT
    cin >> usr_char;  // Perque sempre llegeixi el ')'
    if (op=='+') return num1+num2;
    else if (op=='*') return num1*num2;
    else return num1-num2;
}

int main () {
    char usr_char, op;
    int num1, num2;
    bool op_seen;
    num1 = num2 = 0;
    usr_char = op = 'x';
    op_seen = false;

    cin >> usr_char;
    if (usr_char=='(') cout << recursivitat(num1, num2, op, op_seen) << endl;
    else cout << usr_char << endl;
}