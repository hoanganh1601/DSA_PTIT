#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<int> dp(n + 1, 0);
    dp[1] = x;

    for (int i = 2; i <= n; ++i) {
        if(i % 2 == 0) {
            dp[i] = min(dp[i - 1] + x, dp[i / 2] + z);
        }
        else {
            dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + z + y);
        }
    }

    cout << dp[n] << endl;
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