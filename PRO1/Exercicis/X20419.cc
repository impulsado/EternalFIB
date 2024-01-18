#include <iostream>
#include <vector>
using namespace std;

char lletra_mes_frequent(const string& s) {
    char candidat = '~';
    int last_value = 0;
    const int LONG_ALFABET = 'z'-'a'+1;
    vector<int> vFreq(LONG_ALFABET,0);

    for (int i = 0; i<s.size(); i++) {
        vFreq[s[i]-97]++;
    }

    for (int i = 0; i<s.size(); i++) {
        if (vFreq[s[i]-97]>last_value) {
            candidat = s[i];
            last_value = vFreq[s[i]-97]; 
        } else if (vFreq[s[i]-97]==last_value and s[i]<candidat) {
            candidat = s[i];
        }
    }

    return candidat;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    string usr_paraula, lletra;
    double usr_quant, mitjana, suma;
    vector<string> vWords;
    suma = mitjana = 0;

    cin >> usr_quant;

    // Demanar paraules i calcular mitjana
    for (int i = 0; i<usr_quant; i++) {
        cin >> usr_paraula;
        vWords.push_back(usr_paraula);
        suma = suma + usr_paraula.size();
    }
    mitjana = suma/usr_quant;

    cout << mitjana << endl;

    // Seleccionar paraules que superin/igualin a la mitjana
    for (int i = 0; i<usr_quant; i++) {
        if (vWords[i].size()>=mitjana) {
            lletra = lletra_mes_frequent(vWords[i]);
            cout << vWords[i] << ": " << lletra << endl;
        }
    }
}