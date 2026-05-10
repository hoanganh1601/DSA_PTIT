#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge;
unordered_set<int> adj[1005];
vector<pair<int, int>> edges;
bool visited[1005];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

int tplt() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();
        edges.clear();

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
            edges.push_back({min(u, v), max(u, v)});
        }

        int cc = tplt(); // khong bo qua canh nao
        vector<pair<int, int>> bridges;

        for (pair<int, int> e : edges) {
            int s = e.first, t = e.second;
            adj[s].erase(t);
            adj[t].erase(s);

            if(cc < tplt()) {
                bridges.push_back({s, t});
            }

            adj[s].insert(t);
            adj[t].insert(s);
        }

        sort(bridges.begin(), bridges.end());

        for (pair<int, int> x : bridges) {
            cout << x.first << " " << x.second << " ";             
        }
        cout << endl;
    }

    return 0;
}