#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> dp(n);
    int arr[n]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    int maxRes = arr[0];
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        maxRes = max(maxRes, dp[i]);
    }

    cout << maxRes << endl;
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