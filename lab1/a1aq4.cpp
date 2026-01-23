#include<bits/stdc++.h>
#include<vector>
#include<climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<pair<int,int>> vals;
    for (int i = 0; i < n; i++)
        vals.push_back({A[i], i});


    sort(vals.begin(), vals.end(), greater<>());

    vector<int> B(n, 0);          
    long long answer = 0;
    int ptr = 0;


    for (int idx = 0; idx < n; idx++) {
        int x = vals[idx].first;

        while (ptr < n && vals[ptr].first > x) {
            B[vals[ptr].second] = 1;
            ptr++;
        }


        int prefix = 0;
        bool found = false;

        for (int i = 0; i < n; i++) {
            prefix += B[i];
            if ((prefix - k) == 0) {
                found = true;
                break;
            }
        }

        if (found) {
            answer += x;
        }
    }

    cout << answer << '\n';
    return 0;
}
