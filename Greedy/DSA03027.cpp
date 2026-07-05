#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> arr(n);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(arr[i] > 0) {
            sum += 2 * arr[i];
        }
    }

    cout << sum << endl;

    return 0;
}