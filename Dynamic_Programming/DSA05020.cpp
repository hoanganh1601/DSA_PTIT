#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int row, col; cin >> row >> col;
    int arr[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(row, vector<int>(col, 1e9));
    dp[0][0] = arr[0][0];

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

           if(i >= 1 && j >= 1 && dp[i - 1][j - 1] != 1e9) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);

           if(i >= 1 && dp[i - 1][j] != 1e9) dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i][j]);
           if(j >= 1 && dp[i][j - 1] != 1e9) dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[i][j]);
        }
    }
    
    cout << dp[row - 1][col - 1] << endl;
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