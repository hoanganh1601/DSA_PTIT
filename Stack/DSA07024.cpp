#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> left(n, -1), right(n, n);

    // min left;
    stack<int> st1;
    for (int i = n - 1; i >= 0; --i) {
        if(st1.empty()) st1.push(i);
        else if(a[st1.top()] < a[i]) st1.push(i);
        else {
            while(!st1.empty() && a[st1.top()] > a[i]) {
                left[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
    }

    // min right;
    stack<int> st2;
    for (int i = 0; i < n; ++i) {
        if(st2.empty()) st2.push(i);
        else if(a[st2.top()] < a[i]) st2.push(i);
        else {
            while(!st2.empty() && a[st2.top()] > a[i]) {
                right[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
    }

    // for (int x : left) cout << x << " ";
    // cout << endl;
    // for (int x : right) cout << x << " ";
    // cout << endl;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll len = right[i] - left[i] - 1;
        if(a[i] <= len) res = max(res, a[i]);
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