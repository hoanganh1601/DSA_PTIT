#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
vector<int> adj[100005];
bool vs[100005];

void solve() {
    bool ok = true;

    for (int i = 1; i <= vertex; ++i) {
        if(!vs[i]) {
            int curVertex = 0;
            int totalDeg = 0;

            queue<int> q;
            q.push(i);
            vs[i] = true;

            while(!q.empty()) {
                int cur = q.front(); q.pop();
                ++curVertex;
                totalDeg += adj[cur].size();
                for (int v : adj[cur]) {
                    if(!vs[v]) {
                        q.push(v);
                        vs[v] = true;
                    }
                }
            }

            if(totalDeg != (curVertex - 1) * curVertex) {
                ok = false;
                break;
            }
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        memset(vs, false, sizeof(vs));

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve();

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}