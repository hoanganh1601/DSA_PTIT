#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        ll a[n + 1], b[n + 1];
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n ; ++i) cin >> b[i];

        sort(a, a + n); sort(b, b + n, greater<ll>());
        ll res = 0;

        for (int i = 0; i < n; ++i) {
            res += a[i] * b[i];
        }

        cout << res << endl;
    }

    return 0;
}