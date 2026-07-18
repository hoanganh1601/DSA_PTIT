#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
vector<int> adj[21];
bool vs[21][21];

int maxRoad;

void dfs(int u, int curRoad) {
    maxRoad = max(maxRoad, curRoad);

    for (int v : adj[u]) {
        if(!vs[u][v]) {

            vs[u][v] = true;
            vs[v][u] = true;

            dfs(v, curRoad + 1);
        
            vs[u][v] = false;
            vs[v][u] = false;
        }
    }
}

void solve() {
    cin >> vertex >> edge;
    for (int i = 0; i < edge; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxRoad = 0;

    for (int i = 0; i < vertex; ++i) {
        memset(vs, false, sizeof(vs));
        dfs(i, 0);
    }

    cout << maxRoad << endl;
    
    for (int i = 0; i < vertex; ++i) {
        adj[i].clear();
    }
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