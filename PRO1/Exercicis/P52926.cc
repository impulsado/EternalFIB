#include <iostream>
using namespace std;

void invers(int end_found) {
    string word;
    int found = end_found;

    while (cin >> word) {
        if (word == "end") found = 1;
        else invers(found);
    }

    if (word != "" and found == 0) cout << word << endl;
} 

int main () {
    invers(0);
}