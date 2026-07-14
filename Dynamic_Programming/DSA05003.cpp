#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll dp[101][101][101];

void solve() {

    int sizeX, sizeY, sizeZ;
    cin >> sizeX >> sizeY >> sizeZ;

    string x, y, z;
    cin >> x >> y >> z;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= sizeX; ++i) {
        for (int j = 1; j <= sizeY; ++j) {
            for (int k = 1; k <= sizeZ; ++k) {
                if(x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }

    cout << dp[sizeX][sizeY][sizeZ] << endl;
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