#include <iostream>
using namespace std;

int operacio (char op) {
    char usr_char;
    int num1, num2;

    cin >> usr_char;
    if (usr_char=='+' or usr_char=='-' or usr_char=='*') num1 = operacio(usr_char);
    else num1 = usr_char - '0';

    cin >> usr_char;
    if (usr_char=='+' or usr_char=='-' or usr_char=='*') num2 = operacio(usr_char);
    else num2 = usr_char - '0';

    if (op=='+') {return num1+num2;}
    else if (op=='-') {return num1-num2;}
    else {return num1*num2;}

}

int main () {
    char usr_op;

    cin >> usr_op;
    if (usr_op=='+' or usr_op=='-' or usr_op=='*') cout << operacio(usr_op) << endl;
    else cout << usr_op << endl;
}