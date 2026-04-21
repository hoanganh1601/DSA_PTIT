#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int n, k;
const int MOD = (int)1e9 + 7;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> n >> k;

        // if(k >= n) 

        vector<int> dp(n + 1, 0); // dp[i]: số cách có thể đến đươc bậc thứ i
        dp[0] = 1; // There is exactly 1 way to stand at the ground level before making any moves 

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