#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if(n < 2) {
        cout << 0 << endl;
        return;
    }

    // precompute prefix max
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = max(prefix[i - 1], arr[i]);
    } 

    // precompute suffix min
    vector<ll> suffix(n);
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = min(suffix[i + 1], arr[i]);
    }

    // find valid split points
    vector<ll> ans;
    for(int i = 0; i < n - 1; ++i) {
        // If the maximum on the left is <= the minimum on the right
        if(prefix[i] <= suffix[i + 1]) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (ll x : ans) cout << x << " ";
    cout << endl;
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