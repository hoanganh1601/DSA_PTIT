#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int pre[1005];

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> pre[i];
        }
        sort(pre + 1, pre + 1 + n);

        int mid = (1 + n) / 2;
        cout << pre[mid] << endl;
    }

    return 0;
}