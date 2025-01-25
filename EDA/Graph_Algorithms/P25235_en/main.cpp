#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;  // <cost, vei>
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

void bfs_dijkstra(const VVPII& graph, const int& vertex_inici, const int& vertex_final) {
    int num_vertexs = graph.size();
    bool solved = false;  // determinar si he pogut arribar
    priority_queue<PII, VPII, greater<PII>> PQ;  // Que sigui greater significa que cost menor --> top
    VI vcosts(num_vertexs, INT32_MAX);
    VI vdist(num_vertexs, INT32_MAX);  // Guardar distancies per a cada node
    VI vseen(num_vertexs, 0);  // true or false de vists

    vcosts[vertex_inici] = 0;
    vdist[vertex_inici] = 0;  // Distancia minima a cada 
    PQ.push({0, vertex_inici});

    while (!PQ.empty()) {
        auto [act_cost, act] = PQ.top();
        PQ.pop();

        // === BASE CASE ===
        // 0. Si és el final, simplement marquem com que es pot arribar i ja veurem la longitud del cami fora
        if (act == vertex_final) solved = true;

        // 1. El cost sempre estic fent de l'acumulat
        if (act_cost > vcosts[act]) continue;
        //if (vseen[act]) continue;
        vseen[act] = 1;

        // === GENERAL CASE ===
        for (auto [vei_cost, vei] : graph[act]) {
            int new_cost = vcosts[act] + vei_cost;
            int new_dist = vdist[act]+1;
            //if (vseen[vei]) continue;
            if (new_cost > vcosts[vei]) continue;  // Si el cost és superior a un ja vist, no interessa
            if (new_cost == vcosts[vei] && vdist[vei]<=new_dist) continue;
            vdist[vei] = new_dist; 
            vcosts[vei] = new_cost;  // Marcar el cost total fins arribar
            PQ.push({new_cost, vei});
        }
    }
    
    if (solved) cout << "cost " << vcosts[vertex_final] << ", " << vdist[vertex_final] << " step(s)" << endl;
    else cout << "no path from " << vertex_inici << " to " << vertex_final << endl;
}

int main(void) {
    int usr_num_vertex, usr_num_edges;
    
    while (cin >> usr_num_vertex >> usr_num_edges) {
        VVPII graph(usr_num_vertex, VPII());


        int x,y,c;
        for (int i = 0; i<usr_num_edges; i++) {cin >> x >> y >> c; graph[x].push_back({c,y});}

        int usr_vertex_inici, usr_vertex_final;
        cin >> usr_vertex_inici >> usr_vertex_final;

        bfs_dijkstra(graph, usr_vertex_inici, usr_vertex_final);
    }
}