#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int weights, n; 
    cin >> weights >> n;
    vector<int> cows(n + 1); 
    for (int i = 1; i <= n; ++i) cin >> cows[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(weights + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= weights; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(cows[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cows[i]] + cows[i]);
        }
    }
    cout << dp[n][weights];

    return 0;
}