#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

bool DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(!visited[v]) {
            parent[v] = u;
            if(DFS(v)) return true;
        }
        // backward edge
        else if(v != parent[u]) return true;
    }
    return false;
}

void solve() {
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; ++i) adj[i].clear();
    memset(parent, 0, sizeof(parent));
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= edge; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            if(DFS(i)) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}