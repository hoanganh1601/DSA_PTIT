#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll ugly[10005];

void precompute() {
    ugly[1] = 1;

    int i2 = 1, i3 = 1, i5 = 1;
    for (int i = 2; i <= 10000; ++i) {
        ll next2 = ugly[i2] * 2;
        ll next3 = ugly[i3] * 3;
        ll next5 = ugly[i5] * 5;

        ll nextUgly = min(min(next2, next3), next5);
        ugly[i] = nextUgly;

        if(nextUgly == next2) ++i2;
        if(nextUgly == next3) ++i3;
        if(nextUgly == next5) ++i5;
    }
}

void solve() {
    int n; cin >> n;
    cout << ugly[n] << endl;
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precompute();

    int test; cin >> test;
    while(test--) {
        solve();
    }    

    return 0;
}