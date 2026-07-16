#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

/*
dp[i]: represents the max length of a valid subsequence ending at index i
*/

void solve() {
    int n; cin >> n;

    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> dp(n, 1); 
    int maxVal = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(a[i] > a[j] && b[i] < b[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxVal = max(maxVal, dp[i]);
    }

    cout << maxVal << endl;
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