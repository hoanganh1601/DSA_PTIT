#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll MOD = 1000000000000007LL; 
ll M[5] = {1, 3, 6, 12, 23};

struct matran {
    ll f[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0}
    };
};

ll Mul(ll a, ll b) {
	if (b <= 1) return a % MOD * b;
	ll tmp = Mul(a, b / 2);
	if (b % 2 == 0) return tmp % MOD + tmp % MOD;
	else return tmp % MOD + tmp % MOD + a % MOD;
}

matran operator*(matran A, matran B) {
    matran C;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            C.f[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                C.f[i][j] = (C.f[i][j] + Mul(A.f[i][k], B.f[k][j])) % MOD;
            }
        }
    }
    return C;
}

matran Pow(matran X, ll k) {
    if (k == 1) return X;
    matran tmp = Pow(X, k / 2);
    if (k % 2 == 0) return tmp * tmp;
    else return tmp * tmp * X;
}

ll Tribonaci(ll n) {

    if (n <= 5) return M[n - 1];
    matran X;
    matran S = Pow(X, n + 2);
    
    // Corrected subtraction modulo logic
    return (S.f[2][0] - 1 + MOD) % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int test; 
    cin >> test;
    while (test--) {
        ll n; cin >> n;
        cout << Tribonaci(n) << endl;
    }
    return 0;
}