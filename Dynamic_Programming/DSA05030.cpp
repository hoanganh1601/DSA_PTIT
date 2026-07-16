#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll dp[26][26];

void precompute() {
    // Base case
    dp[0][0] = 0;
    for (int i = 0; i <= 25; ++i) dp[i][0] = 1;
    for (int j = 0; j <= 25; ++j) dp[0][j] = 1;

    for (int i = 1; i <= 25; ++i) {
        for (int j = 1; j <= 25; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    cout << dp[n][m] << endl;
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