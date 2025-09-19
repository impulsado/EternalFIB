#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;

// Sempre anem de 0 --> 1
void bfs_dijkstra(const VVPII& vcarreteres) {
    int num_ciutats = vcarreteres.size();
    priority_queue<PII, VPII, greater<PII>> PQ;
    VI vcarretera_llarga(num_ciutats, INT32_MAX);
    // no importa el cost aqui simplement la carretera mes gran
    // no importa si l'hem vist, perque pot ser hi ha una altra ruta 

    vcarretera_llarga[0] = 0;  // Ciutat inici no te carretera a ella mateixa.
    PQ.push({0,0});

    while (!PQ.empty()) {
        auto [carretera_act, ciutat_act] = PQ.top();
        PQ.pop();

        // === BASE CASE ==
        // 0. Ficar aqui vseen[ciutat_act] fa WA.

        // 1. Si la carretera que va a la ciutat és més gran que una que ja hem vist abans, no interessa.
        // Sempre busquem la més curta (tot i que mencionem quina es la mes llarga de totes aquestes).
        if (carretera_act>vcarretera_llarga[ciutat_act]) continue;

        for (auto [carretera_vei, ciutat_vei] : vcarreteres[ciutat_act]) {
            // Si la carretera que conecta aquestes ciutats es més gran que ja una altra que ha arribat, no vull mirar més.
            //if (carretera_act>=vcarretera_llarga[ciutat_vei]) continue;
            // Si la carretera que va cap al vei és més llarga d'una que ja hem arribat d'alguna altra forma, no interessa.
            // Aixo significa que ja hi ha un altre cami que hem arrosegat una carretera "llarga" pero que es més curta que aquesta nova.
            if (carretera_vei>=vcarretera_llarga[ciutat_vei]) continue;
            
            // Ara volem determinar quina es la nova carretera llarga que volem arrosegar.  
            int nova_carretera_llarga;
            // Si la carretera al vei és més gran que l'actual arrosegada fins aquest punt, significa que volem la del vei.
            if (carretera_vei>vcarretera_llarga[ciutat_act]) nova_carretera_llarga = carretera_vei;
            // Altrament significa que l'arrosegada en algun punt previ es mes que la que va al vei
            else nova_carretera_llarga = vcarretera_llarga[ciutat_act];
            // Adjudiquem la nova "més llarga"
            vcarretera_llarga[ciutat_vei] = nova_carretera_llarga;
            // Insertem el vei amb la més "curta" de les llarges
            PQ.push({nova_carretera_llarga, ciutat_vei});
        }
    }

    cout << vcarretera_llarga[1] << endl;

    return;  // Sempre hi ha solucio
}

int main(void) {
    int usr_num_ciutats, usr_num_carreteres;
    int ciutat_inici, ciutat_desti, cost_carretera;

    while (cin >> usr_num_ciutats >> usr_num_carreteres) {
        VVPII vcarreteres(usr_num_ciutats, VPII());

        for (int i = 0; i<usr_num_carreteres; i++) {
            cin >> ciutat_inici >> ciutat_desti >> cost_carretera;
            vcarreteres[ciutat_inici].push_back({cost_carretera, ciutat_desti});
        }

        bfs_dijkstra(vcarreteres);
    }
}