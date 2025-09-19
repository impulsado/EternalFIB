#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> VI;

typedef set<int> SI;  // Faig set perque literal pot estar diverses vegades mateixa clausula
typedef vector<SI> VSI;

typedef pair<char,bool> PCB;  // <literal, es_negat>
typedef vector<PCB> VPCB;
typedef vector<VPCB> VVPCB;

bool _solved;

bool clausules_ok(const VVPCB vclausules, const VSI& vclausules_relacionades, const VI& vsol, const VI& vseen, const char literal) {
    bool possible;
    for (int num_clausula : vclausules_relacionades[literal-'a']) {
        possible = false;
        for (int i = 0; i<3 && !possible; i++) {
            PCB temp = vclausules[num_clausula][i];
            if (!vseen[temp.first-'a']) {possible = true; continue;}
            int valor_literal = vsol[temp.first-'a'];
            if (temp.second) valor_literal = !valor_literal;
            if (valor_literal) possible = true;
        }
        if (!possible) return false;
    }

    return true;
}

void solve(const VVPCB& vclausules, const VSI& vclausules_relacionades, VI& vsol, VI& vseen, int index) {
    int n = vsol.size();

    // === BASE CASE ===
    if (index == n) {
        _solved = true;
        char literal;
        for (int lit = 0; lit<n-1; lit++) {
            literal = 'a'+lit;
            if (vsol[lit] == 0) cout << '-';
            cout << literal << ' ';
        }
        literal = 'a'+(n-1);
        if (vsol[n-1] == 0) cout << '-';
        cout << literal << endl;
        return;
    }

    // === GENERAL CASE ===
    vseen[index] = 1;
    // Opcio1: Normal
    vsol[index] = 1;
    // 1. Si no fa false cap, continuar
    if (clausules_ok(vclausules, vclausules_relacionades, vsol, vseen, 'a'+index)) solve(vclausules, vclausules_relacionades, vsol, vseen, index+1);

    // Opcio2: Negat
    vsol[index] = 0;
    // 1. Si no fa false cap, continuar
    if (clausules_ok(vclausules, vclausules_relacionades, vsol, vseen, 'a'+index)) solve(vclausules, vclausules_relacionades, vsol, vseen, index+1);
    vseen[index] = 0;
}

int main(void) {
    int usr_num_literals, usr_num_clausules;
    cin >> usr_num_literals >> usr_num_clausules;
    VVPCB vclausules(usr_num_clausules, VPCB(3));  // guardar les clausules
    VSI vclausules_relacionades(usr_num_literals, SI());  // Guardar a quines clausules apareix literal
    VI vsol(usr_num_literals);  // Guardar el registre de si apareix normal (1) o negat (0) el literal i-essim
    VI vseen(usr_num_literals, 0);

    // === Demanar dades
    for (int clausula = 0; clausula<usr_num_clausules; clausula++) {
        for (int literal = 0; literal<3; literal++) {
            string lit;
            PCB temp;
            cin >> lit;
            // Determinar si es negat
            if (lit[0] == '-') {temp.first = lit[1]; temp.second = true;}
            else {temp.first = lit[0]; temp.second = false;}
            // Guardar a la clausula c_i
            vclausules[clausula][literal] = temp;
            // Guardar que apareix en la clausula c_i
            vclausules_relacionades[temp.first-'a'].insert(clausula);
        }
    }

    // === Mostrar totes les convinacions
    int index = 0;
    solve(vclausules, vclausules_relacionades, vsol, vseen, index);
    if (!_solved) cout << '-' << endl;
}