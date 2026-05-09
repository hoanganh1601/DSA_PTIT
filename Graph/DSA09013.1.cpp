#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge;
vector<int> adj[1005];
vector<pair<int, int>> edges;
bool visited[1005];

// (s, t) or (t, s) là cạnh cần bỏ qua
void DFS(int u, int s, int t) {
    visited[u] = true;
    for (int v : adj[u]) {
        if((u == s && v == t) || (u == t && v == s)) continue;
        if(!visited[v]) {
            DFS(v, s, t);
        }
    }
}

int tplt(int s, int t) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++cnt;
            DFS(i, s, t);
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
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.push_back({min(u, v), max(u, v)});
        }

        int cc = tplt(-1, -1); // khong bo qua canh nao
        vector<pair<int, int>> bridges;

        for (pair<int, int> e : edges) {
            int s = e.first, t = e.second;
            if(cc < tplt(s, t)) {
                bridges.push_back({s, t});
            }
        }

        sort(bridges.begin(), bridges.end());

        for (pair<int, int> x : bridges) {
            cout << x.first << " " << x.second << " ";             
        }
        cout << endl;
    }

    return 0;
}