#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAXN = 100;
const int MAXSUM = 900;

/*
dp[i][j]: The number of ways to form an i-digit sequence (allowing leading zeros for these suffixes)
such that that sum of its digits is exactly j

i: represents the current length of the sequence (0 <= i <= N) 
j: represents the current sum of the digits (0 <= j <= K)
*/

ll dp[MAXN + 1][MAXSUM + 1];

void precompute() {
    // Base case: Make a sequence of length 0 with a sum of 0 (empty)
    dp[0][0] = 1;

    // Build
    for (int i = 1; i <= MAXN; ++i) {
        for (int sum = 0; sum <= MAXSUM; ++sum) {
            for (int d = 0; d <= 9; ++d) {
                if(sum >= d) {
                    dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - d]) % MOD;
                }
            }
        }
    }
}

void solve() {
    int n, sum; cin >> n >> sum;
    if(sum > 9 * n || (sum == 0 && n > 0)) {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    for (int d = 1; d <= 9; ++d) {
        if(sum >= d) {
            ans = (ans + dp[n - 1][sum - d]) % MOD;
        }
    }

    cout << ans << endl;
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