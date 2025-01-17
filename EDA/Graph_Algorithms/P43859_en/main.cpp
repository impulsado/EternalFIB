#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int bfs_dijkstra(const vector<vector<pair<int,int>>>& G, vector<int>& costos, vector<bool>& vistos, int x_inici, int y_final) {
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > PQ;
    costos[x_inici] = 0;
    PQ.push({0,x_inici});

    while (!PQ.empty()) {
        pair<int,int> actual = PQ.top();
        PQ.pop();

        // === BASE CASE
        if (actual.second == y_final) return costos[actual.second];
        else if (vistos[actual.second]) continue;
        vistos[actual.second] = true;

        // === GENERAL CASE
        for (pair<int,int> vei : G[actual.second]) {
            int calc_dist_vei = costos[actual.second] + vei.first;
            if (calc_dist_vei < costos[vei.second]) costos[vei.second] = calc_dist_vei;
            PQ.push({calc_dist_vei, vei.second});  // Important ficar la nova distancia
            // Pot ser que hi hagi diferents formes d'arribar i volem saber quina de totes es la menor
            // Llavors fiquem la que hem calculat amb la ruta que haguem fet
        }
    }

    return -1;
}

int main() {
    int quant_vert, quant_edg;
    while (cin >> quant_vert >> quant_edg) {
        // === DEMANAR DADAES
        vector<vector<pair<int,int>>> G(quant_vert);
        vector<int> costos(quant_vert, INT32_MAX);
        vector<bool> vistos(quant_vert);
        for (int i = 0; i<quant_edg; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({c,v});  // <cost,v>
        }
        int x_inici, y_final;
        cin >> x_inici >> y_final;

        // === CODI PRINCIPAL
        int dist = bfs_dijkstra(G,costos,vistos,x_inici,y_final);
        if (dist == -1) cout << "no path from " << x_inici << " to " << y_final << endl;
        else cout << dist << endl;
    }
}