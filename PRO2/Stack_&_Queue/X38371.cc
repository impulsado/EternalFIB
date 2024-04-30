#include <iostream>
#include <queue>
using namespace std;

void min_max(queue<int> c, int& min, int& max) {
    min = max = c.front();
    c.pop();
    while (!c.empty()) {
        if (c.front()<min) min = c.front();
        else if (c.front()>max) max = c.front();
        c.pop();
    }
}

int main() {
    int usr_num, min, max;
    double suma = 0;
    queue<int> cua;

    cin >> usr_num;
    min = max = usr_num;
    while (usr_num <= 1000 and usr_num >= -1001) {
        if (usr_num != -1001) {
            if (usr_num<min) min = usr_num;
            if (usr_num>max) max = usr_num;
            suma += usr_num;
            cua.push(usr_num);
        } else if (!cua.empty()) {
            int num_prev = cua.front();
            suma -= num_prev;
            cua.pop();
            if (!cua.empty() and (min==num_prev or max==num_prev)) min_max(cua,min,max);
        }

        if (cua.empty()) {
            min = 1001;
            max = -1001;
            suma = 0;
            cout << 0;
        } else cout << "min " << min << "; max " << max << "; media " << suma/cua.size();
        cout << endl;
        cin >> usr_num;
    }
}