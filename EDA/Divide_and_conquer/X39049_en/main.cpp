#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp(high-low+1);
    int k = 0;
    int left = low, right = mid+1;
    while (left<=mid && right<=high) {
        if (nums[left]<nums[right]) temp[k++] = nums[left++];
        else temp[k++] = nums[right++];
    }
    while (left<=mid) temp[k++] = nums[left++];
    while (right<=high) temp[k++] = nums[right++];
    k = 0;
    for (int i = low; i<=high; i++) nums[i] = temp[k++];
    return;
}

void mergeSort(vector<int>& nums, int low, int high) {
    // === BASE CASE
    if (low == high) return;

    // === GENERAL CASE
    int mid = low + (high-low)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums, low, mid, high);
    return;
}

vector<int> multi(const vector<int>& o, const vector<int>& t) {
    vector<int> p(o.size());
    for (int i = 0; i<p.size(); i++) p[i] = o[t[i]];

    return p;
}

vector<int> power(vector<int>& o, int exp) {
    bool initalized = false;
    vector<int> result;
    while (exp) {
        if (exp%2 && !initalized) {
            result = o;
            initalized = true;
        }
        else if (exp%2) result = multi(result,o);
        o = multi(o,o);
        exp /= 2;
    }

    return result;
}

int main() {
    int quant_num;

    while (cin >> quant_num) {
        vector<int> numbers(quant_num);
        for (int i = 0; i<quant_num; i++) cin >> numbers[i];
        int exp;
        cin >> exp;

        vector<int> result;
        if (exp != 0) {
            result = power(numbers,exp);
            for (int i = 0; i<quant_num-1; i++) cout << result[i] << ' ';
            cout << result[quant_num-1] << endl;
        }
        else {
            mergeSort(numbers,0,quant_num-1);
            for (int i = 0; i<quant_num-1; i++) cout << numbers[i] << ' ';
            cout << numbers[quant_num-1] << endl;
        }
        

    }
    
}