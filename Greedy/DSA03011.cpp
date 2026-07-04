#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        
        ll x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            q.push(x);
        }

        if(q.size() == 1) {
            cout << q.top() % MOD << endl;
            continue;
        }

        ll res = 0;
        while(q.size() >= 2) {
            ll x1 = q.top(); q.pop();
            ll x2 = q.top(); q.pop();

            ll num = (x1 + x2) % MOD;
            res = (res + num) % MOD;
            q.push(num);
        }        

        cout << res << endl;
    }


    return 0;
}