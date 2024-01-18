#include <iostream>
#include <vector>
using namespace std;

int elements_comuns(const vector<int>& X, const vector<int>& Y) {
    int last_pos, counter;
    last_pos = counter = 0;

    for (int i = 0; i<X.size(); i++) {
        for (int j = last_pos; j<Y.size(); j++) {
            if (X[i]==Y[j]) counter++;
            else if (X[i]<Y[j]) {last_pos = j; break;}  // Optimitzar
        } 
    }

    return counter;
}

int main() {
    int n, m;
    while (cin >> m >> n) {

        vector<int> X(m);
        for (int i = 0; i < m; ++i)
            cin >> X[i];

        vector<int> Y(n);
        for (int i = 0; i < n; ++i)
            cin >> Y[i];

        cout << elements_comuns(X, Y) << endl;
    }
    return 0;
}
