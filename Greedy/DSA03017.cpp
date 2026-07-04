#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;


// The reduction in the total value is x^2 - (x - 1)^2 = 2x - 1
void solve() {
    int k; string res; 
    cin >> k >> res;

    unordered_map<char, ll> mp;
    for (char &x : res) {
        ++mp[x];
    }

    priority_queue<ll> pq;
    for (pair<char, ll> tmp : mp) {
        pq.push(tmp.second);
    }
    for (int i = 1; i <= k; ++i) {
        ll x = pq.top(); pq.pop();
        pq.push(--x);
    }

    ll total = 0;
    while(!pq.empty()) {
        ll num = pq.top(); pq.pop();
        total += num * num;
    }
    cout << total << endl;
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