#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {

    int test;
    cin >> test;
    while(test--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> dp(n + 1, 0);
        dp[0] = 1; // có 1 cách để không cần leo bậc nào

        int curSum = dp[0];
        for (int i = 1; i <= n; ++i) {
            dp[i] = curSum;

            curSum = (curSum + dp[i]) % MOD;
            if(i >= k) curSum = (curSum - dp[i - k] + MOD) % MOD;
        }

        cout << dp[n] << endl;
    }

    return 0;
}