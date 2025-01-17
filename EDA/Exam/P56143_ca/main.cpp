#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef pair<int,int> PII;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<int> VI;
typedef vector<VI> VVI;

typedef vector<PII> VPII;
typedef vector<vector<PII>> VVPII;

vector<PII> dirs = {{-1,-1}, {-1,0}, {-1, 1}, 
                    {0,-1},         {0,1},
                    {1,-1}, {1,0}, {1,1}};


bool pos_ok(const VVC& tauler, int x, int y) {
    int num_rows = tauler.size();
    int num_cols = tauler[0].size();
    if (x<0 || x>=num_rows) return false;
    else if (y<0 || y>=num_cols) return false;
    return true;
}

void bfs(const VVC& tauler, VVI& vists, const PII& pos_inicial) {
    queue<PII> Q;
    list<PII> llista_vertexs;
    VVPII vertex_previ(tauler.size(), VPII(tauler[0].size(), PII(-1,-1)));
    
    PII pos_final;
    bool found = false;
    
    Q.push(pos_inicial);
    vists[pos_inicial.first][pos_inicial.second] = 1;
    vertex_previ[pos_inicial.first][pos_inicial.second] = {-1,-1};

    while (!Q.empty() && !found) {
        PII pos_act = Q.front();
        int act_x = pos_act.first;
        int act_y = pos_act.second;
        Q.pop();

        // === BASE CASE
        if (tauler[act_x][act_y] == 'F') {
            found = true;
            pos_final = pos_act;
            continue;
        }
        
        // === GENERAL CASE
        for (auto dir : dirs) {
            int new_x = act_x + dir.first;
            int new_y = act_y + dir.second;
            if (!pos_ok(tauler, new_x, new_y)) continue;
            
            if (vists[new_x][new_y]) continue;
            else if (tauler[new_x][new_y] == 'X') continue;

            vists[new_x][new_y] = true;
            vertex_previ[new_x][new_y] = pos_act;

            Q.push(PII(new_x,new_y));
        }
    }

    if (found) {
        PII pos = pos_final;
        while (!(pos.first == pos_inicial.first && pos.second == pos_inicial.second)) {
            llista_vertexs.push_front(pos);
            pos = vertex_previ[pos.first][pos.second];
        }
        llista_vertexs.push_front(pos_inicial);

        cout << llista_vertexs.size();
        for (auto vertex : llista_vertexs) cout << "  " << vertex.first << ' ' << vertex.second;
        cout << endl;
    }
    else cout << 0 << endl;
}

int main(void) {
    int usr_num_rows, usr_num_cols;

    while (cin >> usr_num_rows >> usr_num_cols) {
        VVC tauler(usr_num_rows, VC(usr_num_cols));
        VVI vists(usr_num_rows, VI(usr_num_cols, 0));
        PII pos_inicial;

        for (int i = 0; i<usr_num_rows; i++) {
            for (int j = 0; j<usr_num_cols; j++) {
                cin >> tauler[i][j];
                if (tauler[i][j] == 'K') pos_inicial = {i,j};
            }
        }

        bfs(tauler, vists, pos_inicial);
    }
}