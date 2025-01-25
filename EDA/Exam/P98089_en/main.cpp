#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> VS;

typedef vector<int> VI;
typedef vector<VI> VVI;

int get_mania(const VVI& vmanies, const VI& vsol, const int& index_prev, const int& ipersona) {
    return vmanies[ipersona][vsol[index_prev]];
}

void solve(const VVI& vmanies, VI& vseen, VI& vsol, VI& vsol_ref, int mania_act, int& mania_ref, int index) {
    int num_persones = vsol_ref.size();

    // === BASE CASE
    if (index == num_persones) {
        if (mania_act < mania_ref) {
            vsol_ref = vsol;
            mania_ref = mania_act;
        }

        return;
    }

    // === GENERAL CASE
    for (int ipersona = 0; ipersona<num_persones; ipersona++) {
        if (vseen[ipersona]) continue;
        int temp_mania_act = mania_act + get_mania(vmanies, vsol, index-1, ipersona);
        if (temp_mania_act>=mania_ref) continue;

        vsol[index] = ipersona;
        vseen[ipersona] = 1;

        solve(vmanies, vseen, vsol, vsol_ref, temp_mania_act, mania_ref, index+1);
        vseen[ipersona] = 0;
    }
}


int main(void) {
    int num_persones;

    while (cin >> num_persones) {
        // Demanar persones
        VS vpersones(num_persones);
        for (int i = 0; i<num_persones; i++) cin >> vpersones[i];

        // Demanar manies
        VVI vmanies(num_persones, VI(num_persones));
        for (int i = 0; i<num_persones; i++) {
            for (int j = 0; j<num_persones; j++) {
                cin >> vmanies[i][j];
            }
        }

        // Muntar solucio referencia
        VI vsol(num_persones);
        VI vseen(num_persones, 0);
        VI vsol_ref(num_persones);
        int mania_act = 0;
        int mania_ref = 0;
        vsol[0] = vsol_ref[0] = 0;  // Sempre la primera
        vseen[0] = 1;
        for (int i = 1; i<num_persones; i++) {
            vsol_ref[i] = i;
            mania_ref += get_mania(vmanies, vsol_ref, i-1, i);
        }

        // Buscar millor solucio
        int index = 1;
        solve(vmanies, vseen, vsol, vsol_ref, mania_act, mania_ref, index);

        // Mostrar millor solucio
        cout << mania_ref << endl;
        for (int i = 0; i<num_persones-1; i++) cout << vpersones[vsol_ref[i]] << ' ';
        cout << vpersones[vsol_ref[num_persones-1]] << endl;
    }

}