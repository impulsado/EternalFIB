#include <iostream>
#include <vector>
using namespace std;

int main () {
    string usr_string;
    int usr_quant, valor, suma;

    // Quantiat de valors
    cin >> usr_quant;
    vector<int> vNums(usr_quant);
    
    // Demanar valors
    for (int i = 0; i<usr_quant; i++) cin >> vNums[i];  

    while (cin >> usr_string) {
        suma = 0;

        for (int i = 0; i<usr_string.size(); i++) {
            if (usr_string[i]=='-') valor = vNums[i]*(-1);
            else valor = vNums[i];

            suma = suma + valor;
        }

        cout << suma << endl;
    }
}