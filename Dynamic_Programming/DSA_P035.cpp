#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<ll, int>;

const ll INF = 1e15;

int n, m, k;
// Adjacency list for Dijkstra: pair<neighbor, weight>
vector<pair<int, ll>> adj[1005];
// dist[i][j]: the shortest distance from target[i] to city j
ll dist[20][1005]; 

int target[20]; // store city 1 and the K destinations
ll dp[(1 << 16) + 1][20];

// Changed return type to ll (long long)
ll calc(int mask, int u) {
    // Base case: All k + 1 important cities have been visited;
    if(mask == (1 << (k + 1)) - 1) {
        return dist[u][1]; // return to City 1
    }

    if(dp[mask][u] != -1) return dp[mask][u];
    
    ll minCost = INF; 
    
    // Try traveling to any of the K + 1 important cities
    for (int v = 0; v <= k; ++v) {
        int cur = 1 << v;
        // if city V is not visited
        if((mask & cur) == 0) {
            int curCity = u;
            int nextCity = target[v];

            if(dist[curCity][nextCity] != INF) {
                int nextMask = mask | cur;
                minCost = min(minCost, dist[curCity][nextCity] + calc(nextMask, v));
            }
        }
    }

    dp[mask][u] = minCost;
    return minCost;
}

void Dijkstra(int startIdx) {
    
    int startCity = target[startIdx];

    for (int i = 1; i <= n; ++i) {
        dist[startIdx][i] = INF;
    }

    // dist from target[startIdx] to startCity is 0
    dist[startIdx][startCity] = 0;

    // <distance, node>
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, startCity});

    while(!pq.empty()) {
        ii cur = pq.top(); pq.pop();

        ll d = cur.first;
        int u = cur.second;

        // Found a shorter path already -> skip
        if(d > dist[startIdx][u]) continue;

        for (ii edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;

            if(dist[startIdx][v] > dist[startIdx][u] + w) {
                dist[startIdx][v] = dist[startIdx][u] + w;
                pq.push({dist[startIdx][v], v});
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    target[0] = 1; // idx 0 is always the starting city 1
    for (int i = 1; i <= k; ++i) {
        cin >> target[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // first is v, second is w
    }

    // Dijkstra: ONLY from the K + 1 important cities
    for (int i = 0; i <= k; ++i) {
        Dijkstra(i);
    }

    // top-down bitmask dp
    memset(dp, -1, sizeof(dp));

    // Start idx 0 (city 1). Mask 1 = 0000..1 -> City 1 is visited;
    ll ans = calc(1, 0);

    if(ans >= INF) cout << -1;
    else cout << ans;

    return 0;
}