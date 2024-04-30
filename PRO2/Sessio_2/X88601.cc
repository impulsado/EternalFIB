// Add or remove includes
#include <iostream>
#include <string>

using namespace std;

// Adapt the header of the function to your case
void reverseSubstring(string &s, int i, int j) {
    // Cas Base
    if (i>j) return;
    // Swap
    char temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    // Recursivitat
    reverseSubstring(s,i+1,j-1);
}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    string s;
    int i, j;
    while (cin >> s >> i >> j) {
        reverseSubstring(s, i, j);
        cout << s << endl;
    }
}
