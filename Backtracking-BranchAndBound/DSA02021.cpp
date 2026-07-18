#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

char findCharacter(ll n, ll len, string &s) {
    if(n <= s.size()) {
        return s[n - 1];
    }

    ll half = len / 2;
    if(n <= half) return findCharacter(n, half, s);
    else {
        if(n == half + 1) return findCharacter(half, half, s);
        else return findCharacter(n - half - 1, half, s);
    }
}

void solve() {
    string s;   
    ll n;

    cin >> s >> n;
    ll len = s.size();

    while(len < n) len *= 2;

    cout << findCharacter(n, len, s) << endl;
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