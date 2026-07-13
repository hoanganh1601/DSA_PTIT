#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[pre][u]: min cost from 'pre' city to 'u' city
pre: (int) - binary bit
*/

int cost[16][16], n, dp[(1 << 15) + 1][16];

int calc(int pre, int u) {
    // Travel all cities
    // 1000 -> 1000 - 1 = 0111
    if(pre == (1 << n) - 1) return 0;
    if(dp[pre][u] != -1) return dp[pre][u]; 

    int minCost = 1e9;

    int curStatus = 1 << n;
    // Bitwise shift
    for (int v = 1; v <= n; ++v) {
        curStatus = curStatus >> 1; // right shift
        // Duplicate bit 1
        if((pre & curStatus) != 0) continue;
        
        // pre | curStatus: is chosing city
        minCost = min(minCost, cost[u][v] + calc(pre | curStatus, v));
    }
    dp[pre][u] = minCost;

    return minCost;
}
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> cost[i][j];
    }

    memset(dp, -1, sizeof(dp));
    int ans = 1e9;

    for (int i = 1; i <= n; ++i) {
        ans = min(ans, calc(0, i));
    }
    cout << ans << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}