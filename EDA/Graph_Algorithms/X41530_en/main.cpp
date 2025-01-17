#include <iostream>
#include <vector>

using namespace std;

void askData(vector<vector<int>>& graph, int quant_edg) {
    for (int i = 0; i<quant_edg; i++) {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

bool dfs(const vector<vector<int>>& graph, int prev, int act, const vector<int>& adj, vector<bool>& vistos, int& counter) {
    for (int i = 0; i<adj.size(); i++) {
        if (vistos[adj[i]] && prev != adj[i]) return true;
        if (!vistos[adj[i]]) {
            vistos[adj[i]] = true;
            if (dfs(graph, act, adj[i], graph[adj[i]], vistos, counter)) return true;  //a
        }
    }
    return false;
}

bool checkCicle(const vector<vector<int>>& graph, vector<bool>& vistos, int& counter) {
    bool existeix = false;
    for (int i = 0; i<graph.size() && !existeix; i++) {
        if (!vistos[i]) {
            vistos[i] = true;
            existeix = dfs(graph, i, i, graph[i], vistos, counter);
            counter++;
        }
    }
    return existeix;
}

int main() {
    int quant_vert, quant_edg;

    while (cin >> quant_vert >> quant_edg) {
        int counter = 0;
        vector<bool> vistos(quant_vert);
        vector<vector<int>> graph(quant_vert, vector<int>());
        
        askData(graph, quant_edg);

        if (!checkCicle(graph, vistos, counter)) cout << counter << endl;
        else cout << "no" << endl;
    }
}