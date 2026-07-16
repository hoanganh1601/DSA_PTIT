#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll dp[1001][1001];

void precompute() {
    // Base case: P(i, 0) = 1;
    for (int i = 0; i <= 1000; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            // dp[i][j] = dp[i-1][j] + j * dp[i-1][j-1]
            ll x1 = (j * dp[i - 1][j - 1]) % MOD;
            ll x2 = dp[i - 1][j] % MOD;

            dp[i][j] = (x1 + x2) % MOD;
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    if(k > n) {
        cout << 0 << endl;
        return;
    }
    else {
        cout << dp[n][k] << endl;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precompute();

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}