#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int n;
ll ans;

void Try(int pos, ll curK, ll curDiv) {
    if(curDiv == n) {
        ans = min(ans, curK);
        return;
    }

    for (int j = 1; ; ++j) {
        if(curK > ans / p[pos]) break;

        curK *= p[pos];

        if(n % (curDiv * (j + 1)) == 0) {
            Try(pos + 1, curK, curDiv * (j + 1));
        }
    }
}

void solve() {
    cin >> n;
    ans = LLONG_MAX;

    Try(0, 1, 1);
    
    cout << ans << endl;
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