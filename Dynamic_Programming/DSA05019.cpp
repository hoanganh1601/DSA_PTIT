#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[i][j]: represent the side length of the largest square whose bottom-right corner is located at cel (i, j)
*/

void solve() {
    int row, col; cin >> row >> col;
    int arr[row][col];
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int maxSize = -1;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> arr[i][j];

            // first row and first col
            if(i == 0 || j == 0) dp[i][j] = arr[i][j];

            else if(arr[i][j] == 1) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }

            else {
                dp[i][j] = 0;
            }

            maxSize = max(maxSize, dp[i][j]);
        }
    }

    cout << maxSize << endl;
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