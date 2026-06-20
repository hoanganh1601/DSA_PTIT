#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

vector<int> par(1005, 0);
int n;

// duong di tu 1
void path(int t) {
    int cur = t;
    vector<int> path;
    path.reserve(n + 5);

    while(cur != 1) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;

        vector<bool> vs(1005, false); // vs: par node
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;

            par[v] = u;
            vs[u] = true;
        }

        for (int i = 2; i <= n; ++i) {
            if(!vs[i]) {
                path(i);
            }
        }

        par.clear();
    }

    return 0;
}