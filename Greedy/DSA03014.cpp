#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

bool isSubsequence(string &par, string &child) {
    int parIdx = 0, childIdx = 0;
    while(parIdx < par.size() && childIdx < child.size()) {
        if(par[parIdx] == child[childIdx]) {
            ++childIdx;
        }
        ++parIdx;
    }
    return childIdx == child.size();
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string res; cin >> res;
        ll num = stoll(res);

        ll k = cbrt(num);
        bool ok = false;

        // Note: use ll i instead of int i
        for (ll i = k; i >= 1; --i) {
            ll ans = i * i * i;
            string tmp = to_string(ans);

            if(isSubsequence(res, tmp)) {
                cout << tmp << endl;
                ok = true;
                break;
            }
        }

        if(!ok) cout << -1 << endl;
    }

    return 0;
}