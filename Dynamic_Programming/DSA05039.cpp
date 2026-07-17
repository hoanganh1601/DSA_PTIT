#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9;
int dp[105][10005];

/*
dp[i][j]: represent the minimum length of a sequence of digits whose sum is exactly i and 
whose sum of squares is exactly j
*/

void precompute() {
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    // find the minimum length for every combination
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            if(dp[i][j] == INF) continue;

            for (int d = 1; d <= 9; ++d) {
                if(i + d <= 100 && j + d * d <= 10000) {
                    dp[i + d][j + d * d] = min(dp[i + d][j + d * d], dp[i][j] + 1);
                }
            }
        }
    }
}

void solve() {
    int a, b; 
    cin >> a >> b;

    // no valid len
    if(dp[a][b] == INF) {
        cout << -1 << endl;
        return;
    } 

    string res = "";
    while(a > 0 && b > 0) {
        // Always try the smallest digits first (1 to 9)
        for (int d = 1; d <= 9; ++d) {
            if(a >= d && b >= d * d && dp[a - d][b - d * d] == dp[a][b] - 1) {
                res += to_string(d);
                a -= d;
                b -= d *d;
                break;
            }
        }
    }

    cout << res << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precompute();

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}