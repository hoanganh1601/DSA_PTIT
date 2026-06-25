#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;


ll power(ll a, ll b) {
    if(a == 1 || b == 0) return 1;

    ll tmp = power(a, b / 2) % MOD;
    tmp = (tmp % MOD) * (tmp % MOD) % MOD;

    if(b % 2 == 1) return (tmp % MOD) * (a % MOD) % MOD;
    return tmp % MOD;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b;
    while(cin >> a >> b) {
        if(a + b == 0) break;

        cout << power(a, b) << endl;
    }

    return 0;
}