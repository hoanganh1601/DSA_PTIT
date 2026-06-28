#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;

const int MOD = (int)1e9 + 7;

ll n, k; 
Matrix I;

Matrix mul(Matrix A, Matrix B) {
    Matrix res(n + 1, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix power(Matrix A, ll k) {
    if(k == 0) return I;

    Matrix tmp = power(A, k / 2);
    tmp = mul(tmp, tmp);

    if(k % 2 == 1) return mul(tmp, A);
    return tmp;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n >> k;
        Matrix res(n + 1, vector<ll>(n + 1, 0));
        I = vector<vector<ll>> (n + 1, vector<ll>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            I[i][i] = 1;
            for (int j = 1; j <= n; ++j) cin >> res[i][j];
        }

        Matrix ans = power(res, k);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cout << ans[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}