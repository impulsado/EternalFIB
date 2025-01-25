#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef priority_queue<int, VI, less<int>> PQI;


void eliminar_valor(PQI& bossa, const int& valor) {
    VI eliminats;
    bool found = false;
    while (!found) {
        int valor_act = bossa.top();
        if (valor_act>valor) {
            eliminats.push_back(valor_act);
            bossa.pop();
        }
        else if (valor_act == valor) {
            found = true;
            bossa.pop();
        }
        else if (valor_act<valor) found = true;
    }

    for (int joia : eliminats) bossa.push(joia);
}

int64_t get_max_value(PQI bossa, const int& num_elements) {
    int counter = 0;
    int64_t value = 0.0;
    while (counter < num_elements && !bossa.empty()) {
        value += bossa.top();
        counter++;
        bossa.pop();
    }

    return value;
}

int main(void) {
    int num_elements;
    cin >> num_elements;

    string usr_op; 
    int usr_valor;
    priority_queue<int, VI, less<int>> PQ;

    while (cin >> usr_op >> usr_valor) {
        if (usr_op == "deixar") PQ.push(usr_valor);
        else if (usr_op == "endur") eliminar_valor(PQ, usr_valor);

        cout << get_max_value(PQ, num_elements) << endl;
    }
}