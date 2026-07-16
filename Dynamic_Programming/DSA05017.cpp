#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> inc(n);
    for (int i = 0; i < n; ++i) {
        inc[i] = arr[i];
        for (int j = 0; j < i; ++j) {
            if(arr[i] > arr[j]) {
                inc[i] = max(inc[i], inc[j] + arr[i]);
            }
        }
    }

    vector<int> dec(n);
    for (int i = n - 1; i >= 0; --i) {
        dec[i] = arr[i];
        for (int j = n - 1; j > i; --j) {
            if(arr[i] > arr[j]) {
                dec[i] = max(dec[i], dec[j] + arr[i]);
            }
        }
    }

    int maxVal = -1;
    for (int i = 0; i < n; ++i) {
        // arr[i] is counted in both inc[i] and dec[i]
        maxVal = max(maxVal, inc[i] + dec[i] - arr[i]);
    }

    cout << maxVal << endl;
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