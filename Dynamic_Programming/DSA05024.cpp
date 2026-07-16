#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) cin >> cost[i];

    // sort(cost.begin(), cost.end());

    vector<ll> dp(k + 1, 0);
    dp[0] = 1; // 1 way create sum = 0, not choose any element
    
    for (int i = 1; i <= k; ++i) {
        for (ll x : cost) {
            if(i >= x) {
                dp[i] = (dp[i] % MOD) + (dp[i - x] % MOD);
                dp[i] %= MOD; 
            }
        }
    }

    // for (int i = 1; i <= k; ++i) {
    //     cout << dp[i] << endl;
    // }

    cout << dp[k] << endl;
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