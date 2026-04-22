#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        int n; cin >> n;
        ll a[n + 1]; for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<ll> dp(n + 1, 0); // dp[i]: số lượng tài sản lớn nhất tại ngôi nhà thứ i
        dp[1] = a[1]; 
        dp[2] = max(a[1], a[2]);

        for (int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }

        cout << dp[n] << endl;
    }

    return 0;
}