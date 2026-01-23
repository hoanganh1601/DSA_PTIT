#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

const int MOD = 1000000007;

signed main(){

    speed;  

    int test;
    cin >> test;

    int n;
    while(test--) {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a, a + n);
        int res = 0;

        for (int i = 1; i < n; ++i) {
            res = (res % MOD) + (i % MOD) * (a[i] % MOD) % MOD;
            res %= MOD;
        }

        cout << res << endl;
    }

    return 0;
}