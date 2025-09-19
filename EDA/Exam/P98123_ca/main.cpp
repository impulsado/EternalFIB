#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int num_elements;
    cin >> num_elements;

    string usr_op;
    long int valor_joia;
    set<long int> sseleccionats;
    set<long int> saltres;

    long int suma = 0;
    while (cin >> usr_op >> valor_joia) {
        if (usr_op == "deixar") {
            if (sseleccionats.size() < num_elements) {
                suma += valor_joia;
                sseleccionats.insert(valor_joia);
            }
            else {
                if (valor_joia < *(sseleccionats.begin())) saltres.insert(valor_joia);
                else {
                    suma += valor_joia;
                    sseleccionats.insert(valor_joia);
                    long int temp = *(sseleccionats.begin());
                    suma -= temp;
                    saltres.insert(temp);
                    sseleccionats.erase(sseleccionats.begin());
                }
            }
        }
        else if (usr_op == "endur") {
            if (valor_joia < *(sseleccionats.begin())) {
                auto it = saltres.find(valor_joia);
                saltres.erase(it);
            }
            else {
                auto it = sseleccionats.find(valor_joia);
                suma -= *it;
                sseleccionats.erase(it);
                if (saltres.size()>0) {
                    it = saltres.end();
                    it--;
                    suma += *it;
                    sseleccionats.insert(*it);
                    saltres.erase(it);
                }
            }
        }

        cout << suma << endl;
    }
}