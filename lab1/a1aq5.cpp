#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int search(int N , int W ,int H ) {
    int low = max(H,W) , high = max(H,W)*3;
    int mid= (high+low)/2;
    while(low<high){
        
        if(((mid/W)*(mid/H)) >= N){
            high = mid;
        }
        else{
            low = mid+1;
        }
        mid =  (high+low)/2;
    }
    return mid;
}


int main(){
    int N = 10 , W =3 , H =2;
    int res = search(N,W,H);
    cout << res;
    return 0;
}