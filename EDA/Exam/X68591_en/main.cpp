#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int get_num_cc(const VVI& graph, VI& vseen, const int& vertex_act) {
    int counter = 1;
    vseen[vertex_act] = 1;

    for (auto vertex_vei : graph[vertex_act]) {
        if (vseen[vertex_vei]) continue;
        counter += get_num_cc(graph, vseen, vertex_vei);
    }

    return counter;
}

int main(void) {
    int usr_num_vertexs, usr_num_edges;

    while (cin >> usr_num_vertexs >> usr_num_edges) {
        // Demanar graph
        VVI graph(usr_num_vertexs, VI());
        int u, v;
        for (int i = 0; i<usr_num_edges; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Buscar max i min
        VI vseen(usr_num_vertexs, 0);
        int cc_min = INT32_MAX, cc_max = -1;
        for (int vertex = 0; vertex < usr_num_vertexs; vertex++) {
            if (vseen[vertex]) continue;
            int cc_act = get_num_cc(graph, vseen, vertex);

            if (cc_act<cc_min) cc_min = cc_act;
            if (cc_act>cc_max) cc_max = cc_act;
        }

        // Mostrar resultat
        cout << cc_min << ' ' << cc_max << endl;
    }
}