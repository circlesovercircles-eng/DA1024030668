#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& nums, int l, int h) {
    int p = nums[h];
    int i = l - 1;
    
    for (int j = l; j < h; j++) {
        if (nums[j] <= p) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[h]);
    return i + 1;
}

void quickSort(vector<int>& nums, int l, int h) {
    if (l < h) {
        int pi = partition(nums, l, h);
        quickSort(nums, l, pi - 1);
        quickSort(nums, pi + 1, h);
    }
}

int main() {
    vector<int> arr = {4, 2, 6, 9, 2};
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
