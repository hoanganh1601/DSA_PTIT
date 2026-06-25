#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

using Matrix = vector<vector<ll>>;

const int MOD = (int) 1e9 + 7;

Matrix I;
ll n, k;

Matrix mul(Matrix A, Matrix B) {
    Matrix res(n + 5, vector<ll>(n + 5, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix power(Matrix A, ll p) {
    if(p == 0) return I;
    
    Matrix tmp = power(A, p / 2);
    tmp = mul(tmp, tmp);
    if(p % 2 == 1) return mul(tmp, A);
    return tmp;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n >> k;

        Matrix A(n + 5, vector<ll>(n + 5, 0));
        I = Matrix (n + 5, vector<ll>(n + 5, 0));
        for (int i = 0; i < n; ++i) {
            I[i][i] = 1;
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }

        Matrix res = power(A, k);

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + res[i][n - 1]) % MOD; 
        }

        cout << ans << endl;
    }

    return 0;
}