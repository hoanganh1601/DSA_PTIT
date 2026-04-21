#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> dp(n + 1, 0); // dp[i]: tổng của dãy con lớn nhất có thể từ phần tử 1 -> i
    
    for (int i = 1; i <= n; ++i) {
        if(a[i] <= 0) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + a[i];
    }

    // for (int i = 1; i <= n; ++i) cout << dp[i] << " ";

    int left, right;
    while(q--) {
        cin >> left >> right;

        cout << dp[right] - dp[left - 1] << endl;
    }

    return 0;
}