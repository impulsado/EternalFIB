#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    cout << setprecision(4) << fixed;

    double sum;
    int counter, min, max;
    string usr_op;
    map<int, int> quantitat;
    
    counter = sum = 0;

    while (cin >> usr_op) {
        if (usr_op == "number") {
            int usr_num;
            cin >> usr_num;

            counter++;
            sum += usr_num;
            quantitat[usr_num]++;

            if (counter == 1) {
                min = max = sum = usr_num;
                cout << "minimum: " << min << ", maximum: " << max << ", average: " << sum/counter << endl;
                continue;
            }

            if (usr_num<min) min = usr_num;
            else if (usr_num>max) max = usr_num;
        }
        else if (usr_op == "delete" and counter > 0) { 
            counter--;
            quantitat[min]--;
            sum -= min;
                
            if (quantitat[min]==0) {
                int min_temp = min;
                min = next(quantitat.begin())->first;
                quantitat.erase(min_temp);
                
            }
        }

        if (counter == 0) cout << "no elements" << endl;
        else cout << "minimum: " << min << ", maximum: " << max << ", average: " << sum/counter << endl;
    }
}