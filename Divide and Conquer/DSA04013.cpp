#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        vector<int> res(n + 1);
        for (int i = 1; i <= n; ++i) cin >> res[i];

        sort(res.begin() + 1, res.begin() + 1 + n);

        int left = 1, right = n / 2 + 1;
        int ans = n;

        while(left <= n / 2 && right <= n) {
            if(res[right] >= res[left] * 2) {
                --ans;
                ++right; ++ left;
            }
            else ++right;
        }

        cout << ans << endl;
    }

    return 0;
}