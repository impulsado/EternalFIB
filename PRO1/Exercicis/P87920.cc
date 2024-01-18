#include <iostream>
#include <vector>
using namespace std;

int main () {
    int usr_quant;

    while (cin >> usr_quant) {
        int suma = 0;
        bool existeix = false;
        vector<int> vNums(usr_quant);
        
        for (int i = 0; i<usr_quant; i++) {
            cin >> vNums[i];
            suma = suma+vNums[i];
        }

        for (int i = 0; i<vNums.size(); i++) {
            if (vNums[i]==suma-vNums[i]) {existeix = true; break;} 
        }

        if (existeix) cout << "YES" << endl; 
        else cout << "NO" << endl;
    }
}