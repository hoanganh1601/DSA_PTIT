#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

bool vs[1005];
int par[1005];
int vertex, edge;
vector<int> adj[1005];
int t;

bool DFS(int u) {
    vs[u] = true;
    for (int v : adj[u]) {
        if(!vs[v]) {
            par[v] = u;
            if(DFS(v)) return true;
        }

        else if(v == 1 && v != par[u]) {
            t = u;
            return true;
        }
    }

    return false;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= vertex; ++i) {
            sort(adj[i].begin(), adj[i].end());
        }

        memset(vs, false, sizeof(vs));
        bool ok = DFS(1);

        if(!ok) cout << "NO" << endl;
        else {
            int cur = t;
            vector<int> path;
            path.reserve(vertex + 50);

            path.push_back(1);
            while(cur != 1) {
                path.push_back(cur);
                cur = par[cur];
            } 
            path.push_back(1);

            reverse(path.begin(), path.end());
            for (int x : path) cout << x << " ";
        }
        cout << endl;

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}