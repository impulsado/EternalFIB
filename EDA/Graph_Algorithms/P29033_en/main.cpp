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

bool dfs(const vector<vector<int>>& graph, const vector<int>& adj, vector<int>& colors, int color_prev) {
    for (int i = 0; i<adj.size(); i++) {
        if (colors[adj[i]] == color_prev) return false;
        if (colors[adj[i]] == -1) {
            colors[adj[i]] = !color_prev;
            if (!dfs(graph, graph[adj[i]], colors, !color_prev)) return false;
        }
    }
    
    return true;
}

bool checkColors(const vector<vector<int>>& graph, vector<int>& colors) {
    int color_act = 0;
    bool es_possible = true;
    
    for (int i = 0; i<graph.size() && es_possible; i++) {
        if (colors[i] == -1) {
            colors[i] = color_act;
            es_possible = dfs(graph, graph[i], colors, color_act);
        }
    }

    return es_possible;
}

int main() {
    int quant_vert, quant_edg;

    while (cin >> quant_vert >> quant_edg) {
        vector<vector<int>> graph(quant_vert, vector<int>());
        askData(graph, quant_edg);
    
        int color_act = 0;
        vector<int> colors(quant_vert, -1);
        
        if (checkColors(graph, colors)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}