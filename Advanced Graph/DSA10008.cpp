#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

using ii = pair<int, int>;

int vertex, edge, s;
vector<ii> adj[1001];

void init() {
    cin >> vertex >> edge >> s;
    for (int i = 1; i <= vertex; ++i) adj[i].clear();
    for (int i = 1; i <= edge; ++i) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }  
}

void Dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<int> dist(vertex + 1, (int)1e9); dist[s] = 0;
    q.push({0, s});

    while(!q.empty()) {
        ii x = q.top(); q.pop();
        int dis = x.first, u = x.second;
        if(dis > dist[u]) continue;

        for (ii tmp : adj[u]) {
            int v = tmp.first, w = tmp.second;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= vertex; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        init();
        Dijkstra();
    }

    return 0;
}