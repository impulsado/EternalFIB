#include <iostream>
#include <vector>
using namespace std;

int main () {
    char usr_char;
    int usr_quant;
    
    // Demanar Frases
    cin >> usr_quant;
    for (int i = 0; i<usr_quant; i++) {
        vector<int> frase1(26,0);  // 26 lletres d'abecedari
        vector<int> frase2(26,0);  // 26 lletres d'abecedari
        
        // Demanar Frase 1
        while (cin >> usr_char and usr_char!='.') {
            // No és una lletra majúscula
            if (usr_char>='A' and usr_char<='Z') frase1[usr_char-'A']++;
        }
        
        // Demanar Frase 2
        while (cin >> usr_char and usr_char!='.') {
            // No és una lletra majúscula
            if (usr_char>='A' and usr_char<='Z') frase2[usr_char-'A']++;
        }
        
        // Comprovar que tinguin mateixa quantitat de lletres.
        bool iguals = true;
        for (int j = 0; j<frase1.size(); j++) {
            if (frase1[j]!=frase2[j]) {
                iguals = false; 
                break;
            }
        }
        
        // Mostrar resultats
        if (iguals) cout << "SI" << endl;
        else cout << "NO" << endl;
    }


}