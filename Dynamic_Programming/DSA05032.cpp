#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[i][j]: represent the min number of insertions needed 
to make the substring from index i to index j a palindrome.
*/

void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0; // A substring of length 1: already a palindrome
    }
    
    // backward
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }

    cout << dp[0][n - 1] << endl;
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