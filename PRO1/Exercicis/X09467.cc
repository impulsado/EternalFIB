#include <iostream>
#include <vector>
using namespace std;

vector<bool> pos_rampas (const vector <int>& V) {
    int tamany = V.size();
    vector<bool> vPos(tamany);

    for (int i = 0; i<tamany-2; i++) {
        if (V[i]>V[i+1] and V[i+1]>V[i+2]) vPos[i] = true;
        else if (V[i]<V[i+1] and V[i+1]<V[i+2]) vPos[i] = true;
        else vPos[i] = false;
    }

    return vPos;
}

int pot_conflictives (const vector <bool>& B) {
    int tamany = B.size();
    int counter = 0;

    for (int i = 0; i<tamany; i++) {
        if (B[i]!=true) continue;
        for (int j = i+1; j<=i+2; j++) {
            if (B[j]!=true) continue;
            else counter++;
        }
    }

    return counter;
}

int main () {
    int usr_quant, conflictives = 0;

    while (cin >> usr_quant) {
        vector<int> vNums(usr_quant);
        vector<bool> vPos;
        for (int i = 0; i<usr_quant; i++) cin >> vNums[i];

        vPos = pos_rampas(vNums);
        cout << "posicions amb rampa:";
        for (int i = 0; i<vPos.size(); i++) {if (vPos[i]==true) cout << " " << i;}
        cout << endl;

        conflictives = pot_conflictives(vPos);
        cout << "potencialment conflictives: " << conflictives << endl;
        cout << "---" << endl;
    }
}