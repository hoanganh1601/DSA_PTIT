#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            // a[j] < a[i] + k

            int target = arr[i] + k;
            vector<int> :: iterator it = lower_bound(arr.begin() + i + 1, arr.end(), target);

            ans += (it - (arr.begin() + i + 1));
        }

        cout << ans << endl;
    }

    return 0;
}