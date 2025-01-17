#include <iostream>
#include <vector>
using namespace std;

void binarySearch(const vector<int>& nums, int a, int& pos) {
    int high = nums.size()-1, low = 0;

    while (low<=high) {
        int mid = low + (high-low)/2;

        if (mid+1 == nums[mid]+a) {
            pos = mid+1;
            high = mid-1;
        }
        else if (mid+1-a < nums[mid]) high = mid-1;
        else low = mid+1;
    }

    return;
}

int main() {
    int quant_num;
    int seq_counter = 0;
    while (cin >> quant_num) {
        // Info seq
        cout << "Sequence #" << ++seq_counter << endl;

        // Demanar numeros
        vector<int> nums(quant_num);
        for (int i = 0; i<quant_num; i++) cin >> nums[i];
        // Demanar guess
        int quant_guess;
        cin >> quant_guess;
        vector<int> guess(quant_guess);
        for (int i = 0; i<quant_guess; i++) {
            int a, x = quant_num+1;
            cin >> a;
            binarySearch(nums,a,x);
            if (x != quant_num+1) cout << "fixed point for " << a << ": " << x << endl;
            else cout << "no fixed point for " << a << endl;
        }
        // Menjar-se salt de linea
        char empty;
        cin.getline(&empty,2);
        cout << endl;
    }
}