#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;

    vector<ll> dp(51, 0);
    dp[0] = 1; // 0 nhay buoc nao
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 50; ++i) dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    int n;
    while(test--) {
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}