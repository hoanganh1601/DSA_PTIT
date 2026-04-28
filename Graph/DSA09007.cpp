#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void BFS(int u, int target) {
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for (int val : adj[x]) {
            if(!visited[val]) {
                visited[val] = true;
                parent[val] = x;
                if(x == target) return;
                q.push(val);
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    
    int vertex, edge, dau, cuoi;
    while(test--) {
        cin >> vertex >> edge >> dau >> cuoi;
        memset(visited, false, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= vertex; ++i) adj[i].clear();

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BFS(dau, cuoi);
        if(!visited[cuoi]) cout << -1 << endl;
        else {
            vector<int> res;
            int tmp = cuoi;
            while(dau != tmp) {
                res.push_back(tmp);
                tmp = parent[tmp];
            }

            res.push_back(dau);
            for (int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
            cout << endl;
        }
    }

    return 0;
}