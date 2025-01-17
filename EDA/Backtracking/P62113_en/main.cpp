#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<pair<int,bool>> VP;
typedef set<int> SI;
/*
0. Demanar dades
1. Tindre vector:
- Comptador de vegades que apareix el numero de la possicio iessima on vcount[i] < 2
- 
*/

void printResult(const VP& vnums, const SI& indexs, const int& x) {
    cout << x << " = ";
    auto first = indexs.begin();
    for (auto i : indexs) {
        if (i == *first) cout << vnums[i].first;
        else cout << " + " << vnums[i].first;
        if (vnums[i].second) cout << "p";
    }
    cout << endl;
}

void solve(const VP& vnums, SI& indexs,  int i, int& sum, const int& x) {
    // === BASE CASE
    if (sum == x) {
        printResult(vnums, indexs, x);
        return;
    }

    // === GENERAL CASE
    int n = vnums.size();
    for (int j = i; j<n; j++) {
        sum += vnums[j].first;
        if (sum<=x) {
            indexs.insert(j);
            solve(vnums, indexs, j+1, sum, x);
            indexs.erase(j);
        }
        sum -= vnums[j].first;
    }
    return;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        VP vnums(2*n);
        SI indexs;
        int usr_num;
        for (int i = 0; i<n; i++) {
            cin >> usr_num;
            vnums[2*i] = {usr_num, false};
            vnums[2*i+1] = {usr_num, true};
        }
        
        sort(vnums.begin(), vnums.end());
        int i, sum;
        i = sum = 0;
        solve(vnums, indexs, i, sum, x);
        cout << "----------" << endl;
    }
}
