#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // Numero de cues
    int usr_num_cues;
    cin >> usr_num_cues;
    cin.ignore();  // Ignorar el salt de linea de despres de llegir "usr_num_cues"
    vector< queue<string> > vCues(usr_num_cues);

    // Afegir persones a cues
    string frase, nom_persona;
    for (int i = 0; i<usr_num_cues; i++) {
        getline(cin,frase);  // Agafar tota la frase amb salts inclossos
        stringstream ss(frase);  // Dividir frase amb paraules (donat que hi ha espai)
        while(ss >> nom_persona) vCues[i].push(nom_persona);
    }

    // Operacions
    string usr_op;
    int num_cua;
    vector<string> sortides;
    while (cin >> usr_op) {
        if (usr_op=="SURT") {
            cin >> num_cua;
            if (num_cua>usr_num_cues or num_cua<1) continue;  // Comprobar num de la cua

            if (!vCues[num_cua-1].empty()) {
                sortides.push_back(vCues[num_cua-1].front());  // Afegir a persones que han sortit
                vCues[num_cua-1].pop();  // Eliminar persona de la cua
            } 
        } else if (usr_op=="ENTRA") {
            cin >> nom_persona >> num_cua;
            if (num_cua>usr_num_cues or num_cua<1) continue;  // Comprobar num de la cua

            vCues[num_cua-1].push(nom_persona);
        }
    }

    // Mostrar resultat
    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    for (int i = 0; i<sortides.size(); i++) cout << sortides[i] << endl;
    cout << endl;
    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i<usr_num_cues; i++) {
        cout << "cua " << i+1 << ":"; 
        while (!vCues[i].empty()) {cout << ' ' << vCues[i].front(); vCues[i].pop();} 
        cout << endl;
    }

}