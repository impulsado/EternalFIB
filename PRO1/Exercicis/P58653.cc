#include <iostream>
using namespace std;

void print_line(char c, string s, bool b) {
    cout << s << "('" << c << "') = ";
    if (b) cout << "true" << endl;
    else cout << "false" << endl;
}

void fLetter(char c) {
    if ((c>=65 and c<=90) or (c>=97 and c<=122)) {
        print_line(c,"letter",true);
    } else {
        print_line(c,"letter",false);
    }
}

void fVowel(char c) {
    if (c==97 or c==101 or c==105 or c==111 or c==117 or c==65 or c==69 or c==73 or c==79 or c==85) {
        print_line(c,"vowel",true);
    } else {
        print_line(c,"vowel",false);
    }
}

void fConsonant(char c) {
    if (c==97 or c==101 or c==105 or c==111 or c==117 or c==65 or c==69 or c==73 or c==79 or c==85) {
        print_line(c,"consonant",false);
    } else if ((c>=65 and c<=90) or (c>=97 and c<=122)) {
        print_line(c,"consonant",true);
    } else {
        print_line(c,"consonant",false);
    }
}

void fUppercase(char c) {
    if (c>=65 and c<=90) {
        print_line(c,"uppercase",true);
    } else {
        print_line(c,"uppercase",false);
    }
}

void fLowercase(char c) {
    if (c>=97 and c<=122) {
        print_line(c,"lowercase",true);
    } else {
        print_line(c,"lowercase",false);
    }
}

void fDigit(char c) {
    if (c>=48 and c<=57) {
        print_line(c,"digit",true);
    } else {
        print_line(c,"digit",false);
    }
}

int main() {
    char usr_char;

    cin >> usr_char;
    
    fLetter(usr_char);
    fVowel(usr_char);
    fConsonant(usr_char);
    fUppercase(usr_char);
    fLowercase(usr_char);
    fDigit(usr_char);
}
