#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int m, n; cin >> m >> n;

        vector<ll> p(m + 1, 0), q(n + 1, 0);

        for (int i = 0; i < m; ++i) cin >> p[i];
        for (int j = 0; j < n; ++j) cin >> q[j];

        // 0 -> (m - 1) + (n - 1) = m + n - 2 --> total: m + n - 1
        vector<ll> res(m + n - 1, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i + j] += p[i] * q[j];
            }
        }

        for (ll x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}