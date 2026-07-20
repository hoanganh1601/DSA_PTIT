#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
int par[2005];
int sz[2005];

void init() {
    int len = vertex * 2;
    for (int i = 1; i <= len; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void Union(int u, int v) {
    u = find(u); v = find(v);

    if(u != v) {
        if(sz[u] > sz[v]) {
            sz[u] += sz[v];
            par[v] = u;
        }
        else {
            sz[v] += sz[u];
            par[u] = v;
        }
    }
}


void solve() {
    cin >> vertex >> edge;
    init();

    bool ok = true;
    for (int i = 1; i <= edge; ++i) {
        int u, v; 
        cin >> u >> v;

        if(!ok) continue;

        // if u and v are forced into the same set
        if(find(u) == find(v)) {
            ok = false;
        }
        else {
            Union(v, u + vertex);
            Union(u, v + vertex);
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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