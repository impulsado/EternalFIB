#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(const VS& vparaules, VVI& vsubconjunts, VI& vseen, int index) {
    int num_paraules = vparaules.size();
    int num_partitions = vsubconjunts.size();

    if (index == num_paraules) {
        for (int p = 0; p<num_partitions; p++) {
            cout << "subconjunt " << p+1 << ": {";
            if (vsubconjunts[p].size() == 0) {cout << "}" << endl; continue;}
            int num_paraules_sub = vsubconjunts[p].size();
            for (int i = 0; i<num_paraules_sub-1; i++) cout << vparaules[vsubconjunts[p][i]] << ',';
            cout << vparaules[vsubconjunts[p][num_paraules_sub-1]] << '}' << endl;
        }
        cout << endl;
        return;
    }

    for (int p = 0; p<num_partitions; p++) {
        vsubconjunts[p].push_back(index);
        solve(vparaules, vsubconjunts, vseen, index+1);
        vsubconjunts[p].pop_back();
    }
}

int main(void) {
    int usr_num_paraules;
    int usr_num_subconjunts;

    cin >> usr_num_paraules;
    VS vparaules(usr_num_paraules);
    for (int i = 0; i<usr_num_paraules; i++) cin >> vparaules[i];
    
    cin >> usr_num_subconjunts;
    VVI vsubconjunts(usr_num_subconjunts, VI());
    
    VI vseen(usr_num_paraules, 0);
    int counter = 0;
    solve(vparaules, vsubconjunts, vseen, counter);
}