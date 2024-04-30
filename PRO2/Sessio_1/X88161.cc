#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector< vector<int> > iMatrix;

struct Equip {
    int id, punts, gols, rebuts;
};

bool customFilter(const Equip& equip1, const Equip& equip2) {
    /*
    punts > gols-rebuts > id
    */
    if (equip1.punts!=equip2.punts) return equip1.punts>equip2.punts;
    else if ((equip1.gols-equip1.rebuts)!=(equip2.gols-equip2.rebuts)) return equip1.gols-equip1.rebuts>equip2.gols-equip2.rebuts;
    else return equip1.id<equip2.id;
}

int main () {
    // Demanar num_equips
    int num_equips;
    cin >> num_equips;
    vector<Equip> equips(num_equips);
    iMatrix partits(num_equips, vector<int>(num_equips));

    // Demanar partits
    int x,y;
    for (int i = 0; i<num_equips; i++) {
        equips[i].id = i;  // Especificar el id per primera vegada.
        for (int j = 0; j<num_equips; j++) {
            
            // Guardar la relació de gols i rebuts
            cin >> x >> y;
            if (i==j) continue;  // No pot jugar contra ell mateix
            equips[i].gols += x; equips[i].rebuts += y;
            equips[j].gols += y; equips[j].rebuts += x;
            
            // Determinar qui ha guanyat
            if (x==y) {  // Empat
                equips[i].punts += 1;
                equips[j].punts += 1;
            } else if (x>y) {  // Guanya equip 'i'
                equips[i].punts += 3;
            } else {  // Guanya equip 'j'
                equips[j].punts += 3;
            }
        }
    }

    // Ordenar resultat
    sort(equips.begin(), equips.end(), customFilter);

    // Mostrar resultat
    for (int i = 0; i<num_equips; i++) {
        cout << equips[i].id+1 << ' ' << equips[i].punts << ' ' << equips[i].gols << ' ' << equips[i].rebuts << endl;
    }
}