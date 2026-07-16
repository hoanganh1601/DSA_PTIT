#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = s.size();

    // dp[i][j] will be true if S[i..j] is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true; 
    }

    // Substrings of length 2   
    for (int i = 0; i < n - 1; ++i) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLen = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
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