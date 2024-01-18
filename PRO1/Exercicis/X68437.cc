#include <iostream>
#include <vector>
using namespace std;

int numberSubsequences(const string &s, char c1, char c2, char c3) {
    bool c1_found, c2_found;
    int counter, c1_counter, c2_counter;
    int tamany = s.size();

    c1_found = c2_found = false;
    counter = c1_counter = c2_counter = 0;

    for (int i = 0; i<tamany; i++) {
        if (s[i]==c1) c1_found = true, c1_counter++;
        else if (c1_found and s[i]==c2) c2_found = true, c2_counter = c2_counter + c1_counter;
        else if (c1_found and c2_found and s[i]==c3) counter = counter + c2_counter;
    }

    return counter;
}

int numberHappySubsequences(const string &s) {  // HAPPY
    int counter = 0;

    counter = numberSubsequences(s,':','-',')');  // :-)
    counter = counter + numberSubsequences(s,'(','-',':');  // (-:
    
    return counter;
}

int numberSadSubsequences(const string &s) {  // SAD
    int counter = 0;

    counter = numberSubsequences(s,':','-','(');  // :-(
    counter = counter + numberSubsequences(s,')','-',':');  // )-:
    
    return counter;
}

int main () {
    int happy, sad;
    string usr_string;
    
    while (cin >> usr_string) {
        happy = numberHappySubsequences(usr_string);
        sad = numberSadSubsequences(usr_string);
        
        cout << happy << ' ' << sad << endl;
    }

}