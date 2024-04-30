#include <iostream>
#include <list>
using namespace std;

bool check_and_delete(list<int>& num_list, int& num) {
    if (num_list.empty()) return false;

    list<int>::iterator it = num_list.begin();

    while (it!=num_list.end()) {
        if (*it==num) {
            num_list.erase(it);
            return true;
        } else it++;
    }

    return false;
}

void min_max (const list<int>& num_list, int& min, int& max) {
    list<int>::const_iterator it = num_list.begin();
    min = max = num_list.front();

    while (it!=num_list.end()) {
        if (*it>max) max = *it; 
        else if (*it<min) min = *it;
        it++;
    }
}

int main () {
    double sum = 0;
    bool is_first = true;
    int op_code, num, min, max;
    list<int> num_list;

    while (cin >> op_code >> num and (op_code!=0 and num!=0)) {
        if (is_first and op_code==-1) min = max = num, is_first = false; 

        if (op_code==-1) {
            sum += num;
            num_list.push_back(num);
            
            if (num>max) max = num;
            else if (num<min) min = num;
            
            cout << min << ' ' << max << ' ' << sum/num_list.size();
        } else if (op_code==-2) {
            if (check_and_delete(num_list, num)) sum -= num;  // Verificar si existeix en la llista i si existeix, elimina la primera aparicio
            if (!num_list.empty()) {
                if (num==min or num==max) min_max(num_list,min,max);  // Reclacular nomes si afecta al min o max
                cout << min << ' ' << max << ' ' << sum/num_list.size();

            } else sum = 0, is_first = true, cout << 0;  // Això significa que està empty aixi que a començar de nou
        }

        cout << endl;
    }
}