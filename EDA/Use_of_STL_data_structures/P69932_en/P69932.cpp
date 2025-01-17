#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string usr_seq;
    
    while (getline(cin, usr_seq)) {
        // Guardar numeros
        map<int, char> llistat;
        stringstream ss(usr_seq);
        int num;        
        while (ss >> num) {
            if (num%2 == 0) llistat[num] = 'e';
            else llistat[num] = 'o';
        }

        // Recorrer mapa
        char is_eq = 'x';
        int counter = 0;
        for (auto num : llistat) {
            if (num.second != is_eq) {
                counter++;
                is_eq = num.second;
            }
        }

        cout << counter << endl;
    }
}