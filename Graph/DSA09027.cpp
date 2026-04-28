#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge;
vector<int> adj[1005];
int id[1005];

void DFS(int u, int curId) {
    id[u] = curId;
    for (int val : adj[u]) {
        if(id[val] == 0) {
            DFS(val, curId);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();
        memset(id, 0, sizeof(id));

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int curId = 1;
        for (int i = 1; i <= vertex; ++i) {
            if(id[i] == 0) {
                DFS(i, curId);
                ++curId;
            }
        }

        int q;
        cin >> q;
        while(q--) {
            int x, y; 
            cin >> x >> y;
            if(id[x] == id[y]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}