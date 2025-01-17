#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string usr_name;
    map<string, int> casino;

    while (cin >> usr_name) {
        string usr_op;
        cin >> usr_op;

        if (usr_op == "enters") {
            if (casino.find(usr_name) != casino.end()) cout << usr_name << " is already in the casino" << endl;
            else casino[usr_name] = 0;
        }
        else if (usr_op == "leaves") {
            if (casino.find(usr_name) == casino.end()) cout << usr_name << " is not in the casino" << endl;
            else {
                cout << usr_name << " has won " << casino[usr_name] << endl;
                casino.erase(usr_name);
            }
        }
        else if (usr_op == "wins") {
            int usr_quant;
            cin >> usr_quant;

            if (casino.find(usr_name) == casino.end()) cout << usr_name << " is not in the casino" << endl;
            else casino[usr_name] += usr_quant;
        }
    }

    cout << "----------" << endl;

    for (auto player : casino) cout << player.first << " is winning " << player.second << endl;
}