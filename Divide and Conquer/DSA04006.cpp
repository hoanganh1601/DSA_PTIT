#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll getLength(ll num) {
    ll bits = 0;
    ll tmp = num;

    while(tmp > 0) {
        ++bits;
        tmp /= 2;
    }

    // 2^bits - 1;
    return (1LL << bits) - 1;
}

ll findBit(ll n, ll pos, ll len) {
    // Base case 
    if(n == 0 || n == 1) return n;

    ll mid = len / 2 + 1;

    if(pos == mid) return n % 2;
    else if(pos < mid) {
        return findBit(n / 2, pos, len / 2);
    }
    else {
        return findBit(n / 2, pos - mid, len / 2);
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        ll n, l, r; 
        cin >> n >> l >> r;

        ll len = getLength(n);
        ll cnt = 0;

        for (ll i = l; i <= r; ++i) {
            cnt += findBit(n, i, len);
        }

        cout << cnt << endl;
    }


    return 0;
}