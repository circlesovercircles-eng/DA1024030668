#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void MERGE(vector<int> &A, int r ,int q , int p){
    int n1 = q-r+1;
    int n2 = p-q;
    vector<int> left;
    vector<int> right;
    for(int i = r ; i<=q;i++){
        left.push_back(A[i]);
    }
    for(int i = q+1 ; i<=p;i++){
        right.push_back(A[i]);
    }
    int i=0,j =0 , k = r;
    i=0, j=0, k=r;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) A[k++] = left[i++];
        else A[k++] = right[j++];
    }
    while(i < n1) A[k++] = left[i++];
    while(j < n2) A[k++] = right[j++];
}

void MERGE_Sort(vector<int> &A , int r , int p){
    if (p>r){
        int q = r + (p-r)/2;
        MERGE_Sort(A,r,q);
        MERGE_Sort(A,q+1,p);
        MERGE(A,r,q,p);
    }
}


int main(){
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    MERGE_Sort(nums,0,nums.size()-1);
    for(auto i : nums){
        cout << i << " ";
    }
    cout <<endl;
    vector<int> nums2 = {38, 27, 43, 3, 9, 82, 10};
    MERGE_Sort(nums2,0,nums2.size()-1);
    for(auto i : nums2){
        cout<<i<<" ";
    }
    cout << endl;
    return 0;
}