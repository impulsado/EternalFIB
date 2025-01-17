#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef map<string,bool> MSB;
typedef vector<string> VS;

void solve(MSB& words, VS v, int i, const int& n) {
    // === BASE CASE
    if (i == n) {
        cout << '(';
        for (int j = 0; j<n-1; j++) cout << v[j] << ',';
        cout << v[n-1] << ')' << endl;
        return;
    }

    // === GENERAL CASE
    for (auto& word : words) {
        if (word.second) continue;

        v[i] = word.first;
        word.second = true;
        solve(words, v, i+1, n);
        word.second = false;
    }
}

int main() {
    int n;
    cin >> n;
    MSB words;
    VS v(n);
    string usr_word;
    for (int i = 0; i<n; i++) {
        cin >> usr_word;
        words[usr_word] = false;
    }
    int i = 0;
    solve(words, v, i, n);
}