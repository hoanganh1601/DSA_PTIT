#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge;
vector<int> adj[1005];
bool visited[1005];

void BFS(int u) {
    visited[u] = true;
    queue<int> q;
    q.push(u);

    while(!q.empty()) {
        int las = q.front(); q.pop();
        for(int v : adj[las]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
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
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= vertex; ++i) adj[i].clear();

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= vertex; ++i) {
            if(!visited[i]) {
                ++ans;
                BFS(i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}