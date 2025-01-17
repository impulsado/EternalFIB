#include <iostream>
#include <vector>
using namespace std;

bool resistant_search(double x, const vector<double>& v) {
    int n = v.size();
    int high = n-1, low = 0;

    while (low<=high) {
        int mid = low + (high-low)/2;
        if (v[mid] == x) return true;
        else if (mid<high && v[mid+1] == x) return true;
        else if (0<mid && v[mid-1] == x) return true;
        else if (v[mid] < x) low = mid+1;
        else high = mid-1;
    }

    return false;
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << resistant_search(x, V) << endl;
        }
    }
}
