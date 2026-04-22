#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        int n, limits;
        cin >> n >> limits;
        vector<int> weights(n + 1), values(n + 1);
        for (int i = 1; i <= n; ++i) cin >> weights[i];
        for (int i = 1; i <= n; ++i) cin >> values[i];

        vector<vector<int>> dp(n + 1, vector<int>(limits + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= limits; ++j) {
                // not pick
                dp[i][j] = dp[i - 1][j];

                // pick
                if(weights[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }

        cout << dp[n][limits] << endl;
    }

    return 0;
}