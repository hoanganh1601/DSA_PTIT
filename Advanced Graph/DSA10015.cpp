#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge{
    int x, y, weight;
};

int parent[10005], sz[10005];
vector<Edge> edgeList;
int vertex, edge;

bool cmp(Edge x, Edge y) {
    return x.weight < y.weight;
}

void init() {
    cin >> vertex >> edge;
    edgeList.clear();
    for (int i = 1; i <= edge; ++i) {
        Edge tmp;
        cin >> tmp.x >> tmp.y >> tmp.weight;
        edgeList.push_back(tmp);
    }


    for (int i = 1; i <= vertex; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
}

int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;

    if(sz[u] < sz[v]) {
        parent[u] = v;
        sz[v] += sz[u];
    }
    else {
        parent[v] = u;
        sz[u] += sz[v];
    }

    return true;
}

void Kruskal() {
    vector<Edge> MST;
    int res = 0;

    for (Edge tmp : edgeList) {
        if(MST.size() == vertex - 1) break; 
        if(Union(tmp.x, tmp.y)) {
            MST.push_back(tmp);
            res += tmp.weight;
        }
    }

    if(MST.size() == vertex - 1) {
        cout << res << endl;
    }
    else cout << 0 << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        init();
        Kruskal();
    }

    return 0;
}