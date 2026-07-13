#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
3 1 2 : 001
1 1 2 : 101
1 4 2 : 111

dp[i][j] : the maximum value choosing until row i with j: mask j at (i - 1)th col (pre)
*/

int n;
int arr[21][21], dp[21][1 << 21];

int calc(int curRow, int mask) {
    if(curRow > n) return 0;
    if(dp[curRow][mask] != -1) return dp[curRow][mask];

    int costMax = -1;
    int cur = 1 << (n - 1);

    for (int j = 1; j <= n; ++j) {
        // int cur = 1 << j;
    
        // jth col isn't visited
        if((mask & cur) == 0) {
            ll nextMask = mask | cur; // union, choosing jth col
            costMax = max(costMax, calc(curRow + 1, nextMask) + arr[curRow][j]);
        }

        cur = cur >> 1;
    }

    dp[curRow][mask] = costMax;
    return costMax;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> arr[i][j];
    }

    memset(dp, -1, sizeof(dp));
    int ans = calc(1, 0);
    cout << ans << endl;
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