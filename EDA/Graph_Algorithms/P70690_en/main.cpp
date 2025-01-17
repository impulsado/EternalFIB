#include <iostream>
#include <vector>

using namespace std;

bool checkMovments(vector<pair<int,int>>& movments, const vector<vector<char>>& M, const vector<vector<bool>>& visited, int x, int y) {
    if (x-1>=0 && !visited[x-1][y]) {  // AMUNT
        if (M[x-1][y] == 't') return true;
        else if (M[x-1][y] == '.') {
            pair<int,int> temp;
            temp.first = x-1;
            temp.second = y;
            movments.push_back(temp);
        }
    }
    if (y-1>=0 && !visited[x][y-1]) {  // ESQUERRA
        if (M[x][y-1] == 't') return true;
        else if (M[x][y-1] == '.') {
            pair<int,int> temp;
            temp.first = x;
            temp.second = y-1;
            movments.push_back(temp);
        }
    }
    if (y+1<M[0].size() && !visited[x][y+1]) {  // DRETA
        if (M[x][y+1] == 't') return true;
        else if (M[x][y+1] == '.') {
            pair<int,int> temp;
            temp.first = x;
            temp.second = y+1;
            movments.push_back(temp);
        }
    }
    if (x+1<M.size() && !visited[x+1][y]) {  // AVALL
        if (M[x+1][y] == 't') return true;
        else if (M[x+1][y] == '.') {
            pair<int,int> temp;
            temp.first = x+1;
            temp.second = y;
            movments.push_back(temp);
        }
    }

    return false;
}

bool findTreasure(const vector<vector<char>>& M, vector<vector<bool>>& visited, int x, int y) {
    // === BASE CASE
    // Ens assegurem que la primera posiciÃ³ es buida aixi que no fa falta comprovar x,y
    visited[x][y] = true;

    // Comprovar si ens podem moure i arribar a un tressor
    vector<pair<int,int>> movments;
    if (checkMovments(movments, M, visited, x, y)) return true;
    if (movments.empty()) return false;

    // === GENERAL CASE
    // Moures
    bool found = false;
    for (int i = 0; i<movments.size() && !found; i++) {
        found = findTreasure(M, visited, movments[i].first, movments[i].second);
    }
    
    return found;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> M(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> M[i][j];
            visited[i][j] = false;
        }
    }
    

    int c, r;
    cin >> c >> r;

    if (findTreasure(M, visited, c-1, r-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}