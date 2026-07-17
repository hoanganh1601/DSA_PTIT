#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    
    // substrings of len = 1
    for (int i = 0; i < n; ++i) dp[i][i] = true;
    
    // len = 2
    int maxLen = 1;
    for (int i = 1; i < n; ++i) {
        if(s[i] == s[i - 1]) {
            dp[i - 1][i] = true;
            maxLen = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                dp[i][j] = true;
                maxLen = max(maxLen, len);
            }
        }
    }

    cout << maxLen << endl;
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