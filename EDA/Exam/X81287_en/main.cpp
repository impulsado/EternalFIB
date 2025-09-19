#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

typedef vector<int> VI;

int dijkstra_cost(const VVPII& vcarreteres, const VI& vcost_ciutat, const int& ciutat_inicial, const int& ciutat_desti) {
    int cost = 0;
    int num_ciutats = vcost_ciutat.size();

    VI vseen(num_ciutats, 0);
    VI vcosts(num_ciutats, INT32_MAX);
    priority_queue<PII, VPII, greater<PII>> PQ;

    vcosts[ciutat_inicial] = 0;
    PQ.push({0, ciutat_inicial});

    while (!PQ.empty()) {
        auto [cost_act, ciutat_act] = PQ.top();
        PQ.pop();

        // === BASE CASE
        if (vseen[ciutat_act]) continue;
        else if (ciutat_act == ciutat_desti) return vcosts[ciutat_desti]-vcost_ciutat[ciutat_desti];

        // === GENERAL CASE
        vseen[ciutat_act] = 1;
        for (auto vei : vcarreteres[ciutat_act]) {
            int cost_vei = vei.first, ciutat_vei = vei.second;

            if (vseen[ciutat_vei]) continue;
            int cost_temp = vcosts[ciutat_act] + cost_vei+vcost_ciutat[ciutat_vei];
            if (cost_temp>=vcosts[ciutat_vei]) continue;

            vcosts[ciutat_vei] = cost_temp;
            PQ.push({cost_temp, ciutat_vei});
        }
    }

    return -1;
}

int main(void) {
    int usr_num_ciutats, usr_num_carreteres;
    cin >> usr_num_ciutats >> usr_num_carreteres;

    // Demanar cost de cada ciutat
    VI vcost_ciutat(usr_num_ciutats);
    for (int i = 0; i<usr_num_ciutats; i++) cin >> vcost_ciutat[i];

    // Demanar carreteres
    VVPII vcarreteres(usr_num_ciutats, VPII());
    for (int i = 0; i<usr_num_carreteres; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        vcarreteres[u].push_back({c,v});
        vcarreteres[v].push_back({c,u});
    }
    
    // Demanar trajectes
    int ciutat_inici, ciutat_desti;
    while (cin >> ciutat_inici >> ciutat_desti) {
        int cost = 0;

        if (ciutat_inici != ciutat_desti) cost = dijkstra_cost(vcarreteres, vcost_ciutat, ciutat_inici, ciutat_desti);

        cout << "c(" << ciutat_inici << ',' << ciutat_desti << ") = ";
        if (cost == -1) cout << "+oo" << endl;
        else cout << cost << endl;
    }
}