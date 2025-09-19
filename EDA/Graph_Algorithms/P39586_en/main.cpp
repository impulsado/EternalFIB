#include <iostream>
#include <queue>
using namespace std;

bool found;
int counter;
int cost;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VPII> G;

    // Cada vegada que faci pop del final, incrementar +1 les formes d'arribar
void bfs_dijktra(G& graph, const int& vertex_inicial, const int& vertex_final) {
    int num_vertexs = graph.size();
    priority_queue<PII, vector<PII>, greater<PII>> PQ;
    VI vcosts(num_vertexs, INT32_MAX);
    VI vcounter(num_vertexs, 0);
    VI vseen(num_vertexs, 0);

    vcounter[vertex_inicial] = 1;
    vcosts[vertex_inicial] = 0;
    PQ.push({0, vertex_inicial});

    while (!PQ.empty()) {
        auto [vertex_act_cost, vertex_act] = PQ.top();
        PQ.pop();

        // === BASE CASE
        // 0. Es el que buscàvem
        if (vertex_act == vertex_final) {
            found = true;
            vseen[vertex_final] = 1;
            cost = vcosts[vertex_final];
            counter = vcounter[vertex_final];
            return;
        }
        // 1. Ja l'hem vist, per consequencia, més costos
        if (vseen[vertex_act]) continue;
        vseen[vertex_act] = 1;

        // === GENERAL CASE
        // 0. Buscar entre tots els adj
        for (auto [vei_cost, vei] : graph[vertex_act]) {
            int temp_cost_vei = vei_cost + vcosts[vertex_act];
            // 1. Si és superior no ens importa
            if (temp_cost_vei>vcosts[vei]) continue;
            // 2. Si és igual, volem les actuals més les formes diferents d'arribar al previ (arrossegar)
            else if (temp_cost_vei == vcosts[vei]) vcounter[vei] += vcounter[vertex_act];
            // 3. Si és menor (només la primera vegada) volem saber al previ i ja
            else vcounter[vei] = vcounter[vertex_act];
            vcosts[vei] = temp_cost_vei;
            PQ.push({temp_cost_vei, vei});
        }
    }
    
    return;
}

int main(void) {
    int usr_num_vertexs, usr_num_edges;
    int x,y,c;
    while (cin >> usr_num_vertexs >> usr_num_edges) {
        G graph(usr_num_vertexs, VPII());
        cost = INT32_MAX; 
        counter = found = 0;

        for (int i = 0; i<usr_num_edges; i++) {
            cin >> x >> y >> c;
            graph[x].emplace_back(PII(c, y));
        }
        int vertex_inicial, vertex_final;
        cin >> vertex_inicial >> vertex_final;

        bfs_dijktra(graph, vertex_inicial, vertex_final);

        if (!found) cout << "no path from " << vertex_inicial << " to " << vertex_final << endl;
        else cout << "cost " << cost << ", " << counter << " way(s)" << endl;
    }
}