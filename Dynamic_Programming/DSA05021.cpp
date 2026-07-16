#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
dp[i]: stores the maximum chain length ending at pair i
*/

void solve() {
    int n; cin >> n;

    vector<ii> listRes;
    listRes.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        listRes.push_back({x, y});
    }

    sort(listRes.begin(), listRes.end()); // sort the pairs based on their first element
    
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(listRes[i].first > listRes[j].second) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << dp[n - 1] << endl;
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