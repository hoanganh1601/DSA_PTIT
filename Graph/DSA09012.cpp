#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
vector<int> adj[1005];
bool visited[1005];

void DFS(int u, int rev) {
    visited[u] = true;
    for (int v : adj[u]) {
        
        if(v == rev) continue;

        if(!visited[v]) {
            DFS(v, rev);
        }
    }
}

int tplt(int rev) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i] && i != rev) {
            ++cnt;
            DFS(i, rev);
        }
    }

    return cnt;
}

void solve() {
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; ++i) adj[i].clear();

    for (int i = 1; i <= edge; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc = tplt(-1);

    for (int i = 1; i <= vertex; ++i) {
        // articulation point
        int tmp = tplt(i);
        // cout << tmp << endl;
        if(tmp > cc) cout << i << " ";
    }
    cout << endl;
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