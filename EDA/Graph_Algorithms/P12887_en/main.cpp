#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> wedge;  // weight
typedef vector<wedge> vwedge;
typedef vector<vwedge> graph;
typedef vector<int> VI;

int mst(const graph& G) {
    int num_vertexs = G.size()-1;
    VI vseen(num_vertexs+1);
    vector<edge> vecandidates;
    priority_queue<wedge, vwedge, greater<wedge>> PQ;
    int cost_mst = 0;

    for (wedge we : G[1]) PQ.push(we);  // Carregar els adj al vertex 1 (primer)
    vseen[1] = true;  // Marcar-lo com a vist perque pot ser que el vei torni cap endarrere i no volem

    while (vecandidates.size() < num_vertexs-1) {  // Com que es un arbre ha de tindre |E|-1 arestes
        wedge we_act = PQ.top();  // Agafem edge amb menor cost
        int e_cost = we_act.first;
        edge e_uv = we_act.second;  // Agafem vertexs involucrats
        PQ.pop();

        if (vseen[e_uv.second]) continue;  // Si hem vist el vertex, significa que hi havia un cost inferior (I no volem cicles)

        vseen[e_uv.second] = true;  // Marquem el vei com a vist
        cost_mst += e_cost;  // Afegim el cost que ens ha fet inferior
        vecandidates.push_back(e_uv);  // afegim aquest edge a la llista per saber si tenim arbre

        for (wedge we_vei : G[e_uv.second]) PQ.push(we_vei);  // Carregar a la PQ els edges del vei per continuar
    }

    return cost_mst;
}   

int main(void) {
    int usr_num_vertex, usr_num_edges;
    char space;

    while (cin >> usr_num_vertex >> usr_num_edges) {
        graph G(usr_num_vertex+1, vwedge());  // comença per el 1

        //for (int i = 0; i<4; i++) cin >> space;  // Menjarme espais
        int x,y,c;
        for (int i = 0; i<usr_num_edges; i++) {
            cin >> x >> y >> c;
            G[x].push_back({c, {x,y}});
            G[y].push_back({c, {y,x}});
        }

        cout << mst(G) << endl;
    }
}