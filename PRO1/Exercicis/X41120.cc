#include <iostream>
#include <vector>
using namespace std;

vector<int> calcula_cims(const vector<int>& v) {
    vector<int> cims;

    int t1, t2, tamany;
    tamany = v.size();

    for (int i = 0; i<tamany; i++) {
        if (i==0) {t1 = v[i]; continue;}
        else if (i==1) {t2 = v[i]; continue;}

        if (t1<t2 and t2>v[i]) cims.push_back(t2);
        t1 = t2;
        t2 = v[i];
    }

    return cims;
}

int main () {
    int usr_quant;

    // Demanar informació
    cin >> usr_quant;
    vector<int> vPics(usr_quant);
    for (int i = 0; i<usr_quant; i++) cin >> vPics[i];
    
    // Mostrar resultat
    vector<int> vCims = calcula_cims(vPics);
    int tamany = vCims.size();
    bool found = false;

    if (vCims.size()==0) cout << "0:" << endl << "-" << endl;
    else {
        cout << tamany << ":";
        for (int i = 0; i<tamany; i++) cout << " " << vCims[i];
        cout << endl;

        for (int i = 0; i<tamany-1; i++) {
            if (vCims[i]>vCims[tamany-1] and found) {cout << " " << vCims[i];}
            else if (vCims[i]>vCims[tamany-1]) {found = true; cout << vCims[i];}
        }
        if (not found) cout << '-';
        cout << endl;
    }

}