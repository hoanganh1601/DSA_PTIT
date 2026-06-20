#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int n, res;
bool vs[100001];

void dfs(vector<int> adj[], int u, int cnt) {
    res = max(res, cnt);
    vs[u] = true;
    for (int x : adj[u]) {
        if(!vs[x]) {
            dfs(adj, x, cnt + 1);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;
        vector<int> adj[n + 5];
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        res = 0;
        memset(vs, false, sizeof(vs));
        dfs(adj, 1, 0);
        cout << res << endl;
    }

    return 0;
}