#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int arr[n]; for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> inc(n, 1), dec(n, 1);

    for (int i = 1; i < n; ++i) {
        if(arr[i] > arr[i - 1]) inc[i] = inc[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        if(arr[i] > arr[i + 1]) dec[i] = dec[i + 1] + 1;
    }

    // for (int x : inc) cout << x << " ";
    // cout << endl;
    // for (int x : dec) cout << x << " ";

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, inc[i] + dec[i] - 1);
    }

    cout << res << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}