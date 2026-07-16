#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

/*
dp[i][j]: represent the total number of valid ascending numbers of length i 
that end exactly with the digit j
*/


ll dp[101][10];
// ans[i]: the total valid sequences of exactly length 'i'
ll ans[105];

void precompute() {
    // base case
    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    ans[1] = 10;

    for (int i = 2; i <= 100; ++i) {

        dp[i][0] = dp[i - 1][0]; 
        ans[i] = dp[i][0];

        for (int j = 1; j <= 9; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
            ans[i] = (ans[i] + dp[i][j]) % MOD;
        }
    }   
}

void solve() {
    int n; cin >> n;
    cout << ans[n] << endl;
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