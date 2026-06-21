#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int vertex, edge, s;
vector<int> adj[1005];
bool vs[1005];


void DFS(vector<ii> &path, int u) {
    vs[u] = true;
    for (int x : adj[u]) {
        if(!vs[x]) {
            path.push_back({u, x});
            DFS(path, x);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge >> s;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(edge < vertex - 1) {
            cout << -1 << endl;
            continue;
        }
        memset(vs, false, sizeof(vs));
        vector<ii> path;
        path.reserve(vertex + 5);
        DFS(path, s);

        if(path.size() < vertex - 1) {
            cout << -1 << endl;
            continue;
        }
        
        for (ii x : path) {
            cout << x.first << " " << x.second << endl;
        } 

    }

    return 0;
}