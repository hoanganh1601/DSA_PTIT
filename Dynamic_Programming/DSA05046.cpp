#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// dp[i][j] the value of S(i, j).

ll power (ll n, ll k) {
    if(n == 1 || k == 0) return 1;
    ll tmp = power(n, k / 2);

    tmp = (tmp % MOD) * (tmp % MOD) % MOD;

    if(k % 2 == 0) return tmp % MOD;
    else return (n % MOD) * (tmp % MOD) % MOD;
}

ll dp[1005][1005];
void precompute() {
    dp[0][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + (ll)j * dp[i - 1][j]) % MOD;
        }
    }
}

void solve() {
    ll n;
    int k;
    cin >> n >> k;

    if (k == 0) {
        cout << n % MOD << endl;
        return;
    }

    ll ans = 0;
    ll n_mod = n % MOD;
    
    // We maintain the numerator: (n + 1) * n * (n - 1) * ... * (n - j + 1)
    ll num = (n_mod + 1) % MOD; 
    
    for (int j = 1; j <= k; ++j) {
        // Multiply by the next term (n - j + 1)
        num = (num * (n_mod - j + 1 + MOD)) % MOD;
        
        // Fetch our precalculated DP value
        ll term = dp[k][j];
        
        // term = S(k, j) * numerator / (j + 1)
        term = (term * num) % MOD;
        term = (term * power(j + 1, MOD - 2)) % MOD; // Inverse MOD
        
        ans = (ans + term) % MOD;
    }

    cout << ans << endl;
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