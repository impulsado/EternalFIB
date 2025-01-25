#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int topological_sort(VI& vgraus, const VVI& vdependencies, VI& vsol) {
    int num_tasks = vgraus.size();
    int index = 0;
    priority_queue<int, VI, greater<int>> PQ;

    // 1. Fiquem els que tinguin grau 0
    for (int i = 0; i<num_tasks; i++) {
        if (vgraus[i] == 0) PQ.push(i);
    }
    // 2. Si es buit, significa que no hi ha cap grau 0 i no es pot fer topological sort (M'asseguren que tot OK)
    if (PQ.empty()) return -1;

    while (!PQ.empty()) {
        int task = PQ.top();
        PQ.pop();
        vsol[index++] = task;

        for (int tasca_dependent : vdependencies[task]) {
            vgraus[tasca_dependent]--;
            if (vgraus[tasca_dependent] == 0) PQ.push(tasca_dependent);
        }
    }

    if (index != num_tasks) return -1;
    
    for (int i = 0; i<num_tasks-1; i++) cout << vsol[i] << ' ';
    cout << vsol[num_tasks-1] << endl; 
    
    return 0;
}

int main(void) {
    int usr_num_tasks, usr_num_dependencies;
    while (cin >> usr_num_tasks >> usr_num_dependencies) {
        VI vsol(usr_num_tasks);
        VI vgraus(usr_num_tasks, 0);
        VVI vdependencies(usr_num_tasks, VI());

        int vertex_requisit, vertex;
        for (int i = 0; i<usr_num_dependencies; i++) {
            cin >> vertex_requisit >> vertex;
            vdependencies[vertex_requisit].push_back(vertex);
            vgraus[vertex]++;
        }

        topological_sort(vgraus, vdependencies, vsol);
    }

}