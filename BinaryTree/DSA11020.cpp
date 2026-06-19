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

        //ktra tang chat
        bool ok = true;
        for (int i = 2; i <= n; ++i) {
            if(pre[i] <= pre[i - 1]) {
                ok = false;
                break;
            }
        }

        cout << ok << endl;
    }

    return 0;
}