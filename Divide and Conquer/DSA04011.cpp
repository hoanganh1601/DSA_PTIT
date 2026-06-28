#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll convert(string a) {
    ll res = 0;
    ll tmp = 1;

    for (int i = a.size() - 1; i >= 0; --i) {
        res += (a[i] - '0') * tmp;
        tmp *= 2;
    }

    return res;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string a, b; 
        cin >> a >> b;

        ll x1 = convert(a), x2 = convert(b);
        cout << x1 * x2 << endl;
    }

    return 0;
}