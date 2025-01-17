#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> llistat;
    string usr_op;
    string word;

    while (cin >> usr_op) {
        if (usr_op == "minimum?") {
            if (llistat.empty()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << llistat.begin()->first << ", " << llistat.begin()->second << " time(s)" << endl;
        }
        else if (usr_op == "maximum?") {
            if (llistat.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = prev(llistat.end());
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (usr_op == "store") {
            cin >> word;
            llistat[word]++;
        }
        else if (usr_op == "delete") {
            cin >> word;
            if (llistat.find(word) != llistat.end()) {
                llistat[word]--;
                if (llistat[word]<=0) llistat.erase(word);
            }
        }
    }
}