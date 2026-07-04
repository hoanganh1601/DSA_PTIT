#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int sum; cin >> sum;
    int cnt7 = 0, cnt4 = 0;
    
    int k = sum / 7;
    
    bool ok = false;
    for (int i = k; i >= 0; --i) {
        int tmp = sum - i * 7;
        if(tmp % 4 == 0) {
            cnt7 = i;
            cnt4 = tmp / 4;
            ok = true;
            break;
        }
    }

    if(!ok) cout << -1 << endl;
    else {
        for (int i = 1; i <= cnt4; ++i) cout << 4;
        for (int i = 1; i <= cnt7; ++i) cout << 7;
        cout << endl;
    }
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