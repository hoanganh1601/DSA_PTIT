#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge, start;
vector<int> adj[1005];
bool visited[1005];

void DFS(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int x : adj[u]) {
        if(!visited[x]) {
            DFS(x);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> vertex >> edge >> start;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= edge; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= vertex; ++i) sort(adj[i].begin(), adj[i].end());
        
        DFS(start);
        cout << endl;
    }

    return 0;
}