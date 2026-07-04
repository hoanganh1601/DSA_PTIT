#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    ll open = 0, close = 0, imbalance = 0, swaps = 0;

    // imbalance is distance between open bracket and nearest close bracket
    for (char c : s) {
        if(c == ']') {
            ++close;
            if(close > open) ++imbalance;
        }
        else if(c == '[') {
            ++open;
            if(imbalance > 0) {
                swaps += imbalance;
                --imbalance;
            }
        }
    }

    cout << swaps << endl;
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