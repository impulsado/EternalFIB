#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef list<int> LI;

int counter;

void solve(const VI& nums, VB& seen, int i, int& sum, const int& x) {
    // === BASE CASE
    if (sum == x) {
        counter++; 
        return;
    }

    // === GENERAL CASE
    int n = nums.size();
    for (int j = i; j<n; j++) {
        sum += nums[j];
        if (sum <= x) {
            if (seen[j]) solve(nums, seen, j+1, sum, x);
            else {
                seen[j] = true;
                solve(nums, seen, j, sum, x);
                seen[j] = false;
            }
        }
        sum -= nums[j];
    }

    return;
}

int main() {
    int x, n, usr_num;
    while (cin >> x >> n) {
        counter = 0;
        VI nums(n);
        VB seen(n, false);
        for (int i = 0; i<n; i++) cin >> nums[i];
        int i, sum;
        i = sum = 0;
        solve(nums, seen, i, sum, x);
        cout << counter << endl;
    }

    return 0;
}