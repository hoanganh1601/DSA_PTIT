#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

vector<int> adj[1005];
int parent[1005];
bool visited[1005];
int vertex, edge, dau, cuoi;

void DFS(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if(!visited[x]) {
            parent[x] = u;
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
        cin >> vertex >> edge >> dau >> cuoi;
        memset(visited, false, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= vertex; ++i) adj[i].clear();
        
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int i = 1; i <= vertex; ++i) sort(adj[i].begin(), adj[i].end());
        DFS(dau);
        
        if(!visited[cuoi]) cout << -1 << endl;
        else {
            vector<int> res;
            int tmp = cuoi;
            while(dau != tmp) {
                res.push_back(tmp);
                tmp = parent[tmp];
            }

            res.push_back(dau);
            for (int i = res.size() - 1; i >= 0; --i) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}