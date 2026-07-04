#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int s, d; cin >> s >> d;
    if(s > d * 9) {
        cout << -1 << endl;
        return;
    }

    vector<int> res(d);

    // Test case: 
    // 9 2
    // 18
    s -= 1;
    // fill the index from d - 1 -> 1;
    for (int i = d - 1; i >= 1; --i) {
        if(s > 9) {
            res[i] = 9;
            s -= 9;
        }
        else {
            res[i] = s;
            s = 0;
        }
    }

    res[0] = s + 1;
    for (int x : res) cout << x;
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