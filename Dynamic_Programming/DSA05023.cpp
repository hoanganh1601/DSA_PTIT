#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[i]: represent the sum of all substrings that end at index i
*/

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<ll> dp(n + 1, 0);
    dp[0] = s[0] - '0';

    for (int i = 1; i < n; ++i) {
        dp[i] = (i + 1) * (s[i] - '0') + dp[i - 1] * 10;
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += dp[i];
    }
    cout << res << endl;
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