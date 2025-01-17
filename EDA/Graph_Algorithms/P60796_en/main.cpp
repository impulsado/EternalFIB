#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
                                        // UP     DOWN    LEFT   RIGHT
const vector<pair<int,int>> direccions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
const int INF = numeric_limits<int>::max();  // Infinit

bool ok_vei(const vector<vector<char>>& mapa, int x, int y) {
    if (x<0 || x>=mapa.size()) return false;
    else if (y<0 || y>=mapa[0].size()) return false;
    else if (mapa[x][y] == 'X') return false;

    return true;
}

int bfs(const vector<vector<char>>& mapa, vector<vector<int>>& distancies, int x_inici, int y_inici) {
    queue<pair<int,int>> q;
    q.push({x_inici, y_inici});
    distancies[x_inici][y_inici] = 0;

    while (!q.empty()) {
        pair<int,int> act = q.front();
        q.pop();

        for (int i = 0; i<direccions.size(); i++) {
            pair<int,int> adj = act;
            adj.first += direccions[i].first;
            adj.second += direccions[i].second;
            
            if (ok_vei(mapa, adj.first, adj.second) && distancies[adj.first][adj.second] == INF) {
                q.push({adj.first, adj.second});
                distancies[adj.first][adj.second] = distancies[act.first][act.second]+1;
                if (mapa[adj.first][adj.second] == 't') return distancies[adj.first][adj.second];
            }
        }
    }

    return -1;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mapa(n,vector<char>(m));
    vector<vector<int>> distancies(n,vector<int>(m, INF));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> mapa[i][j];
        }
    }

    int x,y;
    cin >> x >> y;

    int dist = bfs(mapa, distancies, x-1, y-1);
    
    if (dist == -1) cout << "no treasure can be reached" << endl;
    else cout << "minimum distance: " << dist << endl;
}