#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll countValidPairs(int x, vector<int>& Y, vector<int>& countY, int m) {
    // If x is 0, x^y > y^x is 0^y > y^0 -> 0 > 1 (Always False)
    if (x == 0) return 0;
    
    // If x is 1, 1^y > y^1 -> 1 > y (True only if y == 0)
    if (x == 1) return countY[0];

    auto it = upper_bound(Y.begin(), Y.end(), x);
    ll valid_count = Y.end() - it;

    // Exceptions for any x > 1: y = 0 and y = 1 always satisfy x^y > y^x
    valid_count += countY[0] + countY[1];

    // Specific exceptions for x = 2 and x = 3
    if (x == 2) valid_count -= (countY[3] + countY[4]); // 2^3 < 3^2 and 2^4 == 4^2
    if (x == 3) valid_count += countY[2]; // 3^2 > 2^3

    return valid_count;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> X(n);
    vector<int> Y(m);
    vector<int> countY(5, 0); 

    for (int i = 0; i < n; ++i) cin >> X[i];

    for (int i = 0; i < m; ++i) {
        cin >> Y[i];
        if (Y[i] < 5) countY[Y[i]]++;
    }

    sort(Y.begin(), Y.end());

    ll total_pairs = 0;
    for (int i = 0; i < n; ++i) {
        total_pairs += countValidPairs(X[i], Y, countY, m);
    }

    cout << total_pairs << endl;
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