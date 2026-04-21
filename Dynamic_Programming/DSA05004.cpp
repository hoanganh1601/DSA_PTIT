#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a[n + 1]; for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> dp(n + 1, 1); // xâu con dài nhất từ 1 -> i;
    int ans = -1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    // for (int i = 1; i <= n; ++i) cout << dp[i] << " ";

    cout << ans;

    return 0;
}