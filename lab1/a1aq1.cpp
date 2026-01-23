#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int low = 0, high = 0;

        for(int i = 0; i < n; i++){
            low = max(low, a[i]);
            high |= a[i];
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int cnt = 1;
            int cur_or = 0;

            for(int i = 0; i < n; i++){
                if((cur_or | a[i]) <= mid){
                    cur_or |= a[i];
                }
                else{
                    cnt++;
                    cur_or = a[i];
                }
            }

            if(cnt <= m){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
