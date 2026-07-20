#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, weight;
};

void solve() {

    int vertex, edge;
    cin >> vertex >> edge;
    
    vector<Edge> edges(edge);
    for (int i = 0; i < edge; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    vector<ll> dist(vertex + 1, 0);
    bool neg = false;

    for (int i = 1; i <= vertex; i++) {
        bool updated = false;
        
        for (Edge& edge : edges) {
            if (dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                updated = true;
                
                if (i == vertex) {
                    neg = true;
                }
            }
        }
        
        if (!updated) break;
    }
    
    if (neg) cout << 1 << endl;
    else cout << 0 << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    
    return 0;
}