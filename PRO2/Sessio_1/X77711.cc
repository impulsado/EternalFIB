#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main() {
    // Demanar num_equips
    int num_equips, num_jornades;
    cin >> num_equips >> num_jornades;
    vector<Equip> equips(num_equips);

    // Assignar valor al camp id
    for (int i = 0; i<num_equips; i++) equips[i].id = i;

    // Relacionat amb els partits
    for (int jornada = 0; jornada<(num_equips/2)*num_jornades; jornada++) {
        // Demanar dades dels partits
        int i,j,x,y;
        cin >> i >> j >> x >> y;

        // Guardar els gols i rebuts
        equips[i-1].gols += x; equips[i-1].rebuts += y;
        equips[j-1].gols += y; equips[j-1].rebuts += x;
        
        // Determinar qui ha guanyat
        if (x==y) {  // Empat
            equips[i-1].punts += 1; equips[j-1].punts += 1;
        } else if (x>y) {  // Guanya equip 'i'
            equips[i-1].punts += 3;
        } else {  // Guanya equip 'j'
            equips[j-1].punts += 3;
        }
    }

    // Ordenar resultat
    sort(equips.begin(), equips.end(), customFilter);

    // Mostrar resultat
    for (int i = 0; i<num_equips; i++) {
        cout << equips[i].id+1 << ' ' << equips[i].punts << ' ' << equips[i].gols << ' ' << equips[i].rebuts << endl;
    }
}