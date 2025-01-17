#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

struct byLength {
    bool operator()(const string& s1, const string& s2) const {
        if (s1.size() != s2.size()) return s1.size() < s2.size();
        else return s1 < s2;
    }
};

int main() {
    int counter = 1;
    string usr_seq;
    bool has_ended = false;
    set<string> has_set;
    set<string, byLength> had_set;
    
    cout << "GAME #" << counter << endl;
    while (getline(cin, usr_seq) and not has_ended) {
        string usr_word;
        stringstream ss(usr_seq);
        
        while (ss >> usr_word) {
            if (usr_word != "QUIT" and usr_word != "END") {
                if (has_set.find(usr_word) == has_set.end()) {
                    has_set.insert(usr_word); // Add to HAS
                    if (had_set.find(usr_word) != had_set.end()) had_set.erase(usr_word);  // Erase from HAD (if existed)
                }  
                else { 
                    has_set.erase(usr_word);  // Erase from HAS
                    had_set.insert(usr_word);  // Add to HAD  
                }
            }
        }
        // If not ended the game, keep reading regardeless the "Enter"
        if (usr_word != "END" and usr_word != "QUIT") continue;

        // Show and Clear "HAS: "
        cout << "HAS:" << endl;
        for (const auto& word : has_set) cout << word << endl;
        has_set.clear();
        
        // Show and Clear "HAD: "
        cout << endl;
        cout << "HAD:" << endl;
        for (const auto& word : had_set) cout << word << endl;
        had_set.clear();
        
        // Quit game
        if (usr_word == "QUIT") {
            has_ended = true;
            continue;
        }
        else counter++;

        cout << endl;
        cout << "GAME #" << counter << endl;
    }
}