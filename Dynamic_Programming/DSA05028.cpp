#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[i][j]: represents the min number of operation required to convert the first i character of str1
into the first j characters of str2
*/

void solve() {
    string s1, s2; 
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case
    // s1 empty
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    // s2 empty 
    for (int i = 0; i <= n; ++i) dp[i][0] = i;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                // dp[i][j-1]: insert
                // dp[i - 1][j]: add
                // dp[i - 1][j - 1]: replace 
            }
        }
    }

    cout << dp[n][m] << endl;
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