#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<char> VC;
typedef vector<VC> VVC;

vector<PII> direccions = {{-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}};

bool pos_ok(const VVC& tauler, const PII& p) {
    if (p.first<0 || p.first>=tauler.size()) return false;
    if (p.second<0 || p.second>=tauler[0].size()) return false;

    return true;
}

int bfs_dist(const VVC& tauler, const PII& pos_inicial) {
    int num_rows = tauler.size();
    int num_cols = tauler[0].size();

    queue<PII> Q;
    VVI vists(num_rows, VI(num_cols,0));
    VVI vsalts(num_rows, VI(num_cols,0));
    
    vists[pos_inicial.first][pos_inicial.second] = 1;
    Q.push(pos_inicial);

    while (!Q.empty()) {
        PII pos_act = Q.front();
        int act_x = pos_act.first, act_y = pos_act.second;
        Q.pop();

        // === BASE CASE
        if (tauler[act_x][act_y] == 'p') return vsalts[act_x][act_y];

        // === GENERAL CASE
        for (auto dir : direccions) {
            int new_x = act_x + dir.first;
            int new_y = act_y + dir.second;

            if (!pos_ok(tauler, {new_x, new_y})) continue;
            if (vists[new_x][new_y]) continue;
            if (tauler[new_x][new_y] == 'X') continue;
            
            vsalts[new_x][new_y] = vsalts[act_x][act_y]+1;
            vists[new_x][new_y] = 1;
            Q.push({new_x, new_y});
        }
    }

    return 0;
}

int main(void) {
    int usr_num_rows, usr_num_cols;

    while (cin >> usr_num_rows >> usr_num_cols) {
        VVC tauler(usr_num_rows, VC(usr_num_cols));

        for (int i = 0; i<usr_num_rows; i++) {
            for (int j = 0; j<usr_num_cols; j++) {
                cin >> tauler[i][j];
            }
        }
        PII pos_inicial;
        cin >> pos_inicial.first >> pos_inicial.second;
        pos_inicial.first--; pos_inicial.second--;

        int num_pasos = bfs_dist(tauler, pos_inicial);

        if (num_pasos == 0) cout << "no" << endl;
        else cout << num_pasos << endl;
    }
}