#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int k; string s;
    cin >> k >> s;

    unordered_map<char, int> mp;
    for (char c : s) ++mp[c];
    priority_queue<ll> pq;

    for(pair<char, int> tmp : mp) {
        pq.push(tmp.second);
    }

    for (int i = 1; i <= k; ++i) {
        ll tmp = pq.top(); pq.pop();
        pq.push(--tmp);
    }

    ll res = 0;
    while(!pq.empty()) {
        ll tmp = pq.top();
        res += tmp * tmp;
        pq.pop();
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