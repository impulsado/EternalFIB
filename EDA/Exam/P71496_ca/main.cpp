#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

typedef vector<int> VI;
typedef vector<VI> VVI;

int dijkstra_estalvi(const VVPII& carreteres) {
    int num_ciutats_visitades = 0;
    int num_ciutats = carreteres.size();
    int cost_minim = 0;

    VI vseen(num_ciutats, 0);
    priority_queue<PII, VPII, greater<PII>> PQ;

    PQ.push({0,0});
    while (num_ciutats_visitades < num_ciutats && !PQ.empty()) {
        PII ciutat_act = PQ.top();
        PQ.pop();

        int cost_act = ciutat_act.first;
        int id_act = ciutat_act.second;

        if (vseen[id_act]) continue;
        vseen[id_act] = 1;
        num_ciutats_visitades++;
        cost_minim += cost_act;

        for (auto vei : carreteres[id_act]) {
            if (vseen[vei.second]) continue;
            PQ.push({vei.first, vei.second});
        }
    }

    return cost_minim;
}

int main(void) {
    int num_ciutats, num_carreteres;
    int x,y,c;
    while (cin >> num_ciutats >> num_carreteres) {
        VVPII carreteres(num_ciutats, VPII());
        int cost_total = 0;
        for (int i = 0; i<num_carreteres; i++) {
            cin >> x >> y >> c;
            carreteres[x].push_back({c,y});
            carreteres[y].push_back({c,x});
            cost_total += c;
        }
        int cost_minim = dijkstra_estalvi(carreteres);
        cout << cost_total - cost_minim << endl;
    }
}