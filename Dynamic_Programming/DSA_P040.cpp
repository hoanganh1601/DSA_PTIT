#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const ll INF = 1e18;

/*
dp[i][mask]: The maximum score: achieve from column 0 up to column i 
             given that column i exactly matches the configuration of mask
*/

int n;
ll arr[4][10005];
ll dp[10005][16]; 
vector<int> valid;

// Precompute all valid masks
void precompute() {
    for (int i = 0; i < 16; ++i) {
        if((i & (i >> 1)) == 0) {
            valid.push_back(i);
        }
    }
}

void solve() {
    cin >> n;
    // 4xN grid
    ll maxVal = -INF;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            maxVal = max(maxVal, arr[i][j]);
        }
    }

    if(maxVal < 0) {
        cout << maxVal << endl;
        return;
    }

    // init dp
    for (int i = 0; i < n; ++i) {
        for (int m : valid) {
            dp[i][m] = -INF;
        }
    }

    // Base Case: Cal scores for the very first column (idx 0)
    for (int m : valid) {
        ll curSum = 0;
        for (int r = 0; r < 4; ++r) {
            // If the r-th bit is set, it means we selected the cell in row r
            if(m & (1 << r)) {
                curSum += arr[r][0];
            }
        }
        dp[0][m] = curSum;
    }

    // Process column by column
    for (int i = 1; i < n; ++i) {
        for (int curMask : valid) {
            ll curSum = 0;
            for (int r = 0; r < 4; ++r) {
                if(curMask & (1 << r)) {
                    curSum += arr[r][i];
                }
            }

            // Try placing it next to every valid mask from the previous column
            for (int prevMask : valid) {
                if((curMask & prevMask) == 0) {
                    dp[i][curMask] = max(dp[i][curMask], dp[i - 1][prevMask] + curSum);
                }
            }
        }
    }

    ll ans = -INF;
    for (int m : valid) {
        ans = max(ans, dp[n - 1][m]);
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