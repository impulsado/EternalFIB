#include <bits/stdc++.h>
using namespace std;

// Definimos una constante para representar infinito
const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    // Procesamos múltiples casos hasta el final de la entrada
    while(cin >> n >> m){
        // Crear una lista de adyacencia para el grafo dirigido
        // adj[u] contiene pares (v, c) donde hay una arista u -> v con costo c
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        
        for(int i=0; i<m; ++i){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
        }
        
        int x, y;
        cin >> x >> y;
        
        // Vector para almacenar el costo mínimo desde x a cada nodo
        vector<long long> dist(n, INF);
        // Vector para almacenar el número mínimo de pasos para el costo mínimo
        vector<int> steps(n, INT32_MAX);
        
        // Usamos una cola de prioridad donde el primer elemento es el costo
        // y el segundo es el nodo actual
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
        
        // Inicializamos el nodo de inicio
        dist[x] = 0;
        steps[x] = 0;
        pq.emplace(0, x);
        
        while(!pq.empty()){
            auto [current_dist, u] = pq.top();
            pq.pop();
            
            // Si ya hemos encontrado una mejor distancia, continuamos
            if(current_dist > dist[u]) continue;
            
            // Exploramos todas las aristas salientes desde u
            for(auto &[v, c] : adj[u]){
                // Calculamos la nueva distancia si tomamos esta arista
                long long new_dist = current_dist + c;
                // Calculamos los nuevos pasos si tomamos esta arista
                int new_steps = steps[u] + 1;
                
                // Si encontramos una mejor distancia, actualizamos
                if(new_dist < dist[v]){
                    dist[v] = new_dist;
                    steps[v] = new_steps;
                    pq.emplace(new_dist, v);
                }
                // Si la distancia es igual pero encontramos un camino con menos pasos
                else if(new_dist == dist[v] && new_steps < steps[v]){
                    steps[v] = new_steps;
                    pq.emplace(new_dist, v);
                }
            }
        }
        
        // Después de Dijkstra, verificamos si hay camino desde x a y
        if(dist[y] == INF){
            cout << "NO PATH\n";
        }
        else{
            cout << dist[y] << " " << steps[y] << "\n";
        }
    }
    
    return 0;
}