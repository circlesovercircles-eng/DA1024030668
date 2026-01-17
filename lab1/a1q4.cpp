#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxsums(vector<int> A){
    int cursum = A[0];
    int maxSum = A[0];

    for(int i = 1 ; i<A.size();i++){
        cursum = max(A[i],A[i]+cursum);
        maxSum = max(cursum,maxSum);
    }
    return maxSum;
}

int main(){
    vector<int> nums ={-2, -5, 6, -2, -3, 1, 5, -6};
    cout << maxsums(nums)<< endl;
    return 0;
}