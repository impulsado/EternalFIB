#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Simplifica l'expresio fixant-se desde l'ultima posicio cap endarrere si hi ha alguna regla aplicable
// S'executa mentre hagi hagut algun canvi (Donat que pot desencadenar a una cadena de canvis)
void simplify(vector<char> &v, char next_char) {
    bool changed = true;
    while (changed) {
        int i = v.size()-1;
        changed = false;
        
        // n -> E
        if (v[i]=='n') {
            v[i] = 'E'; 
            changed = true;
        }
        // v -> E
        else if (v[i]=='v' and next_char!='=') {
            v[i] = 'E';
            changed = true;
        }
        // v=E; -> I
        else if (i>=3 and v[i]==';' and v[i-1]=='E' and v[i-2]=='=' and v[i-3]=='v') {
            v[i-3] = 'I';
            v.erase(v.begin()+(i-2),v.begin()+(i+1));  // Eliminar "=E;"
            changed = true;
        }
        // E[]E
        else if (v[i]=='E') {
            // E*E -> E
            if (i>=2 and v[i-1]=='*' and v[i-2]=='E') {
                v.erase(v.begin()+(i-2),v.begin()+i);  // Eliminar "E*"
                changed = true;
            }
            // E+E -> E
            else if (i>=2 and v[i-1]=='+' and v[i-2]=='E' and next_char!='*') {
                v.erase(v.begin()+(i-2),v.begin()+i);  // Eliminar "E+"
                changed = true;
            }
            // E<E -> E
            else if (i>=2 and v[i-1]=='<' and v[i-2]=='E' and (next_char!='*' and next_char!='+')) {
                v.erase(v.begin()+(i-2),v.begin()+i);  // Eliminar "E<"
                changed = true;
            }
        }
        // (E) -> E
        else if (i>=3 and v[i]==')' and v[i-1]=='E' and v[i-2]=='(' and (v[i-3]!='i' and v[i-3]!='w')) {
            v[i-2] = 'E';
            v.erase(v.begin()+(i-1),v.begin()+(i+1));  // Eliminar "E)"
            changed = true;
        }
        // i(E)IeI --> I
        else if (i>=6 and v[i]=='I' and v[i-1]=='e' and v[i-2]=='I' and v[i-3]==')' and v[i-4]=='E' and v[i-5]=='(' and v[i-6]=='i') {
            v[i-6] = 'I';
            v.erase(v.begin()+(i-5),v.begin()+(i+1));  // Eliminar "(E)IeI"
            changed = true;
        }
        // i(E)I --> I
        else if (i>=4 and v[i]=='I' and v[i-1]==')' and v[i-2]=='E' and v[i-3]=='(' and v[i-4]=='i' and next_char!='e') {
            v.erase(v.begin()+(i-4),v.begin()+i);  // Eliminar "i(E)"
            changed = true;
        }
        // w(E)I --> I
        else if (i>=4 and v[i]=='I' and v[i-1]==')' and v[i-2]=='E' and v[i-3]=='(' and v[i-4]=='w') {
            v.erase(v.begin()+(i-4),v.begin()+i);  // Eliminar "w(E)"
            changed = true;
        }
        // LI --> L
        else if (i>=1 and v[i]=='I' and v[i-1]=='L'){
            v.pop_back();  // Eliminar "I"
            changed = true;
        }
        // I --> L
        else if (i>=1 and v[i]=='I' and (v[i-1]!=')' and v[i-1]!='L')) {
            v[i] = 'L';
            changed = true;
        }
        else if (i==0 and v[i]=='I') {
            v[i] = 'L';
            changed = true;
        }
        // {L} --> I
        else if (i>=2 and v[i]=='}' and v[i-1]=='L' and v[i-2]=='{') {
            v[i-2] = 'I';
            v.erase(v.begin()+(i-1),v.begin()+(i+1));  // Eliminar "L}"
            changed = true;
        }
    }
}

int main () {
    string sentence;

    while (cin >> sentence) {
        vector<char> vTokens;

        for (int i = 0; i<sentence.size()-1; i++) {
            vTokens.push_back(sentence[i]);
            simplify(vTokens, sentence[i+1]);
        }
        // Fer apart l'ultim element perque no peti el i+1
        vTokens.push_back(sentence.back());
        simplify(vTokens, 'x');  // 'x' es un caracter que no esta entre els valids

        // Mostrar els resultats
        if (vTokens.size()==1 and vTokens[0]=='L') {
            cout << 'P';
        } 
        else {
            for (int i = 0; i<vTokens.size(); i++) {
                cout << vTokens[i];
            }
        }

        cout << endl;
    }
}