#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge, m;
int color[15];
vector<int> adj[15];
bool vs[15];

bool check(int u, int c) {
    for (int v : adj[u]) {
        if(color[v] == c) {
            return false;
        }
    }

    return true;
}

bool Try(int u) {
    if(u > vertex) return true;

    for (int c = 1; c <= m; ++c) {
        if(check(u, c)) {
            color[u] = c;
            if(Try(u + 1)) return true;
            color[u] = 0; // remove color
        }
    }

    // nếu đã thử hết các màu -> không có màu nào hợp lệ -> false
    return false;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge >> m;
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        memset(vs, false, sizeof(vs));
        memset(color, 0, sizeof(color));

        if(Try(1)) cout << "YES" << endl;
        else cout << "NO" << endl;

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}