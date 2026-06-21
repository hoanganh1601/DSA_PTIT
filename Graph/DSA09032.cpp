#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
int par[100005], sz[100005];
int res;

void init() {
    res = -1;
    for (int i = 1; i <= vertex; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if(u == par[u]) return u;
    else return par[u] = find(par[u]);
}

void Union(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) {
        sz[u] += sz[v];
        par[v] = u;

        res = max(res, sz[u]);
    }

    else {
        sz[v] += sz[u];
        par[u] = v;

        res = max(res, sz[v]);
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        init();
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        }

        cout << res << endl;
    }

    return 0;
}