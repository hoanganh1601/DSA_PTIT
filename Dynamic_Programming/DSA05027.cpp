#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int n, capacity;

void solve() {
    cin >> n >> capacity;
    int weights[n + 1], values[n + 1];

    for (int i = 1; i <= n; ++i) cin >> weights[i];
    for (int i = 1; i <= n; ++i) cin >> values[i];

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(weights[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }

    cout << dp[n][capacity] << endl;
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