#include <iostream>
#include <vector>
using namespace std;


int first_occurrence(double x, const vector<double>& v) {
    int low = 0, high = v.size()-1;
    int mid = (high+low)/2;
    int last_seen = -1;

    while (low<=high) {
        if (v[mid]==x) {
            last_seen = mid;
            high = mid-1;
        }
        else if (x<v[mid]) high = mid-1;
        else low = mid+1;
        mid = (high+low)/2;
    }

    return last_seen;
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
            cout << first_occurrence(x, V) << endl;
        }
    }
}
