#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        vector<int> value(n + 1); for (int i = 1; i <= n; ++i) cin >> value[i];
        // day con tang dai nhat
        vector<int> dp(n + 1, 1);
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if(value[j] <= value[i]) dp[i] = max(dp[i], dp[j] + 1);
            }

            ans = max(ans, dp[i]);
        }

        cout << n - ans << endl;
    }

    return 0;
}