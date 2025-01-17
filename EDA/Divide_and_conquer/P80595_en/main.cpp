#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& nums, int low, int mid, int high) {
    int k = 0, left = low, right = mid+1, counter = 0;
    vector<int> temp(high-low+1);

    while (left<=mid && right<=high) {
        if (nums[left]>nums[right]) {
            counter += high-right+1;
            temp[k++] = nums[left++];
        }
        else {
            temp[k++] = nums[right++];
        }
    }

    while (left<=mid) temp[k++] = nums[left++];

    while (right<=high) temp[k++] = nums[right++];

    k = 0;
    for (int i = low; i<=high; i++) nums[i] = temp[k++];

    return counter;
}

int mergeSortMOD(vector<int>& nums, int low, int high) {
    // === BASE CASE
    if (low >= high) return 0;
    
    // === GENERAL CASE
    int mid = low + (high-low)/2;
    int left_inv = mergeSortMOD(nums,low,mid);
    int right_inv = mergeSortMOD(nums,mid+1,high);
    int merge_inv = merge(nums, low, mid, high);
    
    return left_inv + right_inv + merge_inv;
}

int main() {
    int quant_num;
    while(cin >> quant_num) {
        vector<int> nums(quant_num);
        for (int i = 0; i<quant_num; i++) cin >> nums[i];
        cout << mergeSortMOD(nums,0,quant_num-1) << endl;
    }
}