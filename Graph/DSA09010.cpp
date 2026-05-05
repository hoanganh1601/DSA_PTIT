#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

int vertex, edge;
vector<int> adj[1005], revAdj[1005];
bool visited[1005];

void DFS(int u, vector<int> res[1005], int &cnt) {
    visited[u] = true;
    ++cnt;
    for (int x : res[u]) {
        if(!visited[x]) {
            DFS(x, res, cnt);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; 
    cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            revAdj[v].push_back(u);
        }

        memset(visited, false, sizeof(visited));
        int cnt1 = 0;
        DFS(1, adj, cnt1);

        if(cnt1 < vertex) {
            cout << "NO" << endl;
            continue;
        }

        memset(visited, false, sizeof(visited));
        int cnt2 = 0;
        DFS(1, revAdj, cnt2);

        if(cnt2 < vertex) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}