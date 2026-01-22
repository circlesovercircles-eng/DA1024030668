#include<bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

int solve(int N, vector<int> A) {
    sort(A.begin(),A.end());
    int i = 0, j = 0;
    int max = 1;
    while(j<N){
        while(abs(A[i]-A[j]) <=10 && j<N){
            j++;
        }
        if(j-i > max){
            max= j-i;
        }
        i++;
        if(j <= i){
            j++;
        }
    }
    return max;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }

    int out_;
    out_ = solve(N, A);
    cout << out_;
}