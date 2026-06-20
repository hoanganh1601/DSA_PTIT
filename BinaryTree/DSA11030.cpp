#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

vector<int> adj[1005];
bool vs[1005];
int res;
bool ok;

void DFS(int u, int v, int cnt){
    if(ok) return;

    vs[u] = true;
    if(u == v) {
        res = cnt;
        ok = true; 
        return;
    }

    for (int x : adj[u]) {
        if(!vs[x]) DFS(x, v, cnt + 1);
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        for (int i = 1; i <= n - 1; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int q; cin >> q;
        while(q--) {
            int u, v; cin >> u >> v;
            memset(vs, false, sizeof(vs));

            res = 0; ok = false;
            DFS(u, v, 0);

            cout << res << endl;
        }

        for (int i = 1; i <= n; ++i) adj[i].clear();
    }

    return 0;
}