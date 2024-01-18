#include <iostream>
#include <vector>
using namespace std;

bool conte(string s1, string s2) {
    bool esta;

    for (int i = 0; i<s1.size(); i++) {
        esta = true;
        if (s1[i]==s2[0]) {  // Optimitzar el codi, donat que si ja la primera no és igual, no mira res.
            for (int j = 0; j<s2.size(); j++) {
                if (s1[i+j]!=s2[j]) {esta = false; break;}
            }
            if (esta) return true;
        }
    }
    return false;
}

int main () {
    int usr_quant;
    bool esta;
    
    // Demanar paraules
    cin >> usr_quant;
    vector<string> vWords(usr_quant);
    for (int i = 0; i<usr_quant; i++) cin >> vWords[i];
    
    // Mostrar paraules
    int tamany = vWords.size();
    for (int i = 0; i<tamany; i++) {
        cout << vWords[i] << ':';
        for (int j = 0; j<tamany; j++) {
            esta = false;  // Reset
            esta = conte(vWords[i], vWords[j]);
            if (esta) cout << " " << vWords[j];
        }
        cout << endl;
    }
}