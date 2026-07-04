#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    ll p, q;
    cin >> p >> q;

    while(true) {
        if(q % p == 0) {
            cout << 1 << "/" << q/p << endl;
            break;
        }
        else {
            ll x = q/p + 1;
            cout << 1 << "/" << x << " + ";
            
            p = p * x - q;
            q = q * x;
        }
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