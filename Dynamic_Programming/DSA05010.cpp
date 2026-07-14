#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int INF = -1e9;

void solve() {
    int n, k; cin >> n >> k;
    int arr[n]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] %= k; // important: because (A + B) % K is the same as ((A % K) + (B % K)) % K
    }

    vector<int> dp(k, INF); // stores: carry when sum % k;

    // Base case: 0 elements chosen means len 0 and remainder 0
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        vector<int> nextDp = dp;

        for (int rem = 0; rem < k; ++rem) {
            // Only branch out from states that are actually reachable
            if(dp[rem] != INF) {
                int nextRem = (x + rem) % k;

                // Keep the previous best (next_dp[next_rem]) or take the new path (dp[rem] + 1) - after add x.
                nextDp[nextRem] = max(nextDp[nextRem], dp[rem] + 1);
            }
        }

        dp = nextDp;
    }

    cout << dp[0] << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}