#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;

    while (t--) {
        unsigned long long n, h, w;
        cin >> n >> h >> w;

        unsigned long long low = max(h, w);
        unsigned long long high = min(h, w) * n;

        while (low < high) {
            unsigned long long mid = low + (high - low) / 2;

            if ((mid / h) * (mid / w) >= n)
                high = mid;
            else
                low = mid + 1;
        }

        cout << low << "\n";
    }
    return 0;
}