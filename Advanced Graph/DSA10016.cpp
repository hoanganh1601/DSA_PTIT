#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Point {
    double x, y;
};

struct Edge {
    int u, v;
    double weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

const int MAXN = 105;
int par[MAXN];
int sz[MAXN];

int Find(int u) {
    if (u == par[u]) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v) {
    u = Find(u); v = Find(v);
    if(u == v) return false;

    if(sz[u] > sz[v]) {
        sz[u] += sz[v];
        par[v] = u;
    }

    else {
        sz[v] += sz[u];
        par[u] = v;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    
    vector<Point> points(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Edge> edges;
    
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double dist = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            edges.push_back({i, j, dist});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    double min_cost = 0.0;
    int edges_used = 0;
    
    for (Edge& edge : edges) {
        if (Union(edge.u, edge.v)) {
            min_cost += edge.weight;
            edges_used++;
            
            if (edges_used == n - 1) {
                break;
            }
        }
    }
    
    cout << fixed << setprecision(6) << min_cost << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}