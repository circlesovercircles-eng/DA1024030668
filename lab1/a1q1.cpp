#include <vector>
#include <iostream>
using namespace std;




int search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;
        
        while(low<=high){
            int mid =  (high+low)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                low = mid+1;
            }
            if(nums[mid] > target){
                high = mid-1;
            }
        }  
        return -1;
}


int main(){
    vector<int> nums = {2,5,8,12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int res = search(nums,target);
    if(res != -1) {
        cout << res <<" is the index of where the target is .\n";
    }
    else{
        cout << "target not found";
    }
    return 0;
}