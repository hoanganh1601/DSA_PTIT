#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
vector<int> adj[1005];
bool vs[1005];

void DFS(int u, int stop) {
    vs[u] = true;
    for(int v : adj[u]) {
        if(v == stop) continue;
        if(!vs[v]) {
            DFS(v, stop);
        }
    } 
}

int tplt(int stop) {
    memset(vs, false, sizeof(vs));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(i == stop) continue;
        if(!vs[i]) {
            ++cnt;
            DFS(i, stop);
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
        for (int i = 1; i <= edge; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cc = tplt(-1);
        for (int i = 1; i <= vertex; ++i) {
            int tmp = tplt(i);
            if(tmp > cc) cout << i << " ";
        }
        cout << endl;

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}