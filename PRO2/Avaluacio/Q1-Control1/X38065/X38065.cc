#include <iostream>
#include <map>
using namespace std;

int main () {
    int coin_num;
    string command, name;
    map<string,int> usrMoney;
    map<int,int> onlyMoney;

    while (cin >> command) {
        if (command=="NUMPEOPLE") {
            cin >> coin_num;
            cout << onlyMoney[coin_num] << endl;
        }
        else if (command=="ADD") {
            cin >> name >> coin_num;
            if (onlyMoney[usrMoney[name]]>0) onlyMoney[usrMoney[name]]--;
            usrMoney[name] += coin_num;
            onlyMoney[usrMoney[name]]++;
        }
        else if (command=="DELETE") {
            cin >> name;
            if (onlyMoney[usrMoney[name]]>0) onlyMoney[usrMoney[name]]--;
            usrMoney.erase(name);
        }
    }
}
