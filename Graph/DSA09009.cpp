#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

vector<int> adj[1005];
bool visited[1005];

void BFS(int u) {
    visited[u] = true;
    queue<int> q;
    q.push(u);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for (int val : adj[x]) {
            if(!visited[val]) {
                visited[val] = true;
                q.push(val);
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;

    int vertex, edge;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= vertex; ++i) adj[i].clear();
        memset(visited, false, sizeof(visited));

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