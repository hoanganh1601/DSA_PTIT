#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll dp[10001];

void precompute() {
    
    // i is made up of i 1s. 
    for (int i = 0; i <= 10000; ++i) {
        dp[i] = i;
    }

    for (int i = 1; i <= 10000; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << dp[n] << endl;
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