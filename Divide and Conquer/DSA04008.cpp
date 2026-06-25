#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

typedef vector<vector<ll>> Matrix;

Matrix I = {{1, 0}, {0, 1}};

Matrix mul(Matrix A, Matrix B) {
    Matrix C(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
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
        ll n; cin >> n;

        Matrix T = {{1, 1}, {1, 0}};

        Matrix res = power(T, n);

        cout << res[1][0] << endl;
    }

    return 0;
}