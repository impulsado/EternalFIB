#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string key_word;

struct byLength {
    /*
    Aixo es per al map:
    true: s1 va abans que s2 ====> s1,s2
    false: s1 es igual o va despres de s2 ====> s2,s1
    

        bool operator()(const string& s1, const string& s2) const {
        if (s1.length() != s2.length()) return s1.length() < s2.length();
        
        string new_keyword = key_word.substr(0,s1.size());
        
        if (s1 == s2) return false;
        if (s1 == new_keyword) return true;
        if (s2 == new_keyword) return false;
        if (s1<s2) {
            if (s1<new_keyword and s2>new_keyword) return false;
            else return true;
        }
        else {  //s2<s1
            if (s1>new_keyword and s2<new_keyword) return true;
            else return false;
        }
    }



    !!!!!!!!!!!! PERO EN PRIORITY QUEUE ES A L'INVERSA !!!!!!!!!!!!!!!!!!!
    */

    bool operator()(const string& s1, const string& s2) const {
        if (s1.length() != s2.length()) return s1.length() > s2.length();
        
        string new_keyword = key_word.substr(0,s1.size());
        
        if (s1 == s2) return false;
        if (s1 == new_keyword) return false;
        if (s2 == new_keyword) return true;
        if (s1<s2) {
            if (s1<new_keyword and s2>new_keyword) return true;
            else return false;
        }
        else {  //s2<s1
            if (s1>new_keyword and s2<new_keyword) return false;
            else return true;
        }
    }
};

int main() {    
    while (cin >> key_word) {
        string usr_op;
        priority_queue<string, vector<string>, byLength> supporters;
        int tickets_counter = 0;

        while (cin >> usr_op) {
            if (usr_op == "S") {
                string supp_name;
                cin >> supp_name;

                if (tickets_counter>0) {
                    cout << supp_name << endl;
                    tickets_counter--;
                } else supporters.push(supp_name);
            }
            else if (usr_op == "T") {
                if (supporters.empty()) tickets_counter++;
                else {
                    // Find the next available supporter
                    string next_supp_name = supporters.top();

                    // Decrease how many tickets he needs
                    cout << next_supp_name << endl;
                    if (tickets_counter>0) tickets_counter--;
                    supporters.pop();
                }
            }
            else {
                // Print results
                cout << tickets_counter << " ticket(s) left" << endl;
                cout << supporters.size() << " supporter(s) with no ticket" << endl;
                cout << endl;
                break;
            }
        }
    }
}