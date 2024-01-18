#include <iostream>
#include <vector>
using namespace std;

int main () {
    int max, num, last_num, counter = 0;
    vector<int> uNums;

    cin >> max;

    for (int i = 1; i<=max; i++) {
        cin >> num;
        uNums.push_back(num);
    }

    last_num = uNums.back();

    for (int i = 0; i < uNums.size(); i++) {
        if (uNums[i]==last_num) counter++;
    }

    if (counter==0) cout << 0 << endl;
    else cout << counter-1 << endl;
}