#include <map>
#include <iostream>
using namespace std;

void show_word_counter(map<string,int>& dictionary, string usr_word) {
    // .find() returns an iterator with the position of the element with 'usr_num' key
    // If it doesn't found it, returns the last position (end)
    if (dictionary.find(usr_word)!=dictionary.end()) cout << dictionary[usr_word] << endl;
    else cout << '0' << endl;
}

void decrement_word_counter(map<string,int>& dictionary, string usr_word) {
    if (dictionary.find(usr_word)!=dictionary.end()) {
        if (dictionary[usr_word]>0) dictionary[usr_word]--;  // Avoid negative numbers
    }
}

int main () {
    char usr_op;
    string usr_word;
    map<string,int> dictionary;

    while (cin >> usr_op >> usr_word) {
        if (usr_op == 'a') dictionary[usr_word]++;  // Create the entry if it doesn't exist or increment it
        else if (usr_op == 'f') show_word_counter(dictionary,usr_word);
        else if (usr_op == 'e') decrement_word_counter(dictionary,usr_word);
    }
}