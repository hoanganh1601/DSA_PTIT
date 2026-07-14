#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll arr[n]; for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<ll> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1]);

    for (int i = 3; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    cout << dp[n - 1] << endl;
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