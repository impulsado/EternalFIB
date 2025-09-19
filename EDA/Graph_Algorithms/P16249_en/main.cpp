#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef list<int> LI;
typedef vector<int> VI;
typedef vector<LI> VLI;
typedef vector<string> VS;

unordered_map<string, int> task_to_index;
bool solved;

void solve(const VS& vtasks, VI& vgrausdedependencia, const VLI& vgeneradependencia, VS& vsol) {
    priority_queue<string, vector<string>, greater<string>> PQ;
    int t = 0;  // index per a vsol

    // 1. Vull agafar els que tenen dependencia 0
    for (int vertex = 0; vertex<vtasks.size(); vertex++) {
        if (vgrausdedependencia[vertex] == 0) PQ.push(vtasks[vertex]);
    }

    // 2. Si no hi cap element a PQ significa que no es possible
    if (PQ.empty() && vtasks.size() > 0) return;

    // 3. Ara amb els que ha agafat vull anar mostrant i actualitzant
    while (!PQ.empty()) {
        string task_act = PQ.top();
        int task_act_index = task_to_index[task_act];
        PQ.pop();

        // 3.1. Guardar la tasca en la solucio (Pot ser no possible)
        vsol[t++] = task_act;

        // 3.2. Anar als que depenien d'aquesta tasca i decrementar
        for (auto task_dependent : vgeneradependencia[task_act_index]) {
            int temp = --vgrausdedependencia[task_dependent];
            if (temp == 0) PQ.push(vtasks[task_dependent]);
        }
    }

    // 4. Si hem sortit d'aqui i t no es el final, significa que hi ha taskes que no hem ficat --> no es pot
    if (t != vtasks.size()) return;

    // 5. Finalment si que hem pogut
    solved = true;
}

int main(void) {
    int usr_num_tasks;
    while (cin >> usr_num_tasks) {
        solved = false;
        VS vtasks(usr_num_tasks);
        VLI vgeneradependencia(usr_num_tasks, LI());  // index i-essim genera dependencia a les tasks {...}
        VI vgrausdedependencia(usr_num_tasks,0);
        string task_prev, task;
        for (int i = 0; i<usr_num_tasks; i++) {
            cin >> task;
            vtasks[i] = task;
            task_to_index[task] = i;
        }
        int usr_restrictions;
        cin >> usr_restrictions;
        for (int i = 0; i<usr_restrictions; i++) {
            cin >> task_prev >> task;
            int task_prev_index = task_to_index[task_prev];
            int task_index = task_to_index[task];
            vgeneradependencia[task_prev_index].emplace_back(task_index);  // task_prev es necessari abans de task
            vgrausdedependencia[task_index]++;
        }
        VS vsol(usr_num_tasks);
        solve(vtasks, vgrausdedependencia, vgeneradependencia, vsol);

        if (!solved) cout << "NO VALID ORDERING";
        else for (int i = 0; i<vtasks.size(); i++) cout << vsol[i];
        cout << endl;
    }
}