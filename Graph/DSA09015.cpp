#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, edge;
int color[1005];
vector<int> adj[1005];

bool DFS(int u) {
    color[u] = 1; // Đang được thăm (nằm trên đường đi đang xét)

    for (int v : adj[u]) {
        if(!color[v]) { // Đỉnh kề chưa được thăm
            if(DFS(v)) return true;
        }

        // IMPORTANT
        else if(color[v] == 1) {
            // Đỉnh kề đang trong đường đi -> tạo thành chu trình
            return true;
        }
    }

    // sau khi đã duyệt hết các định kề (không còn nhánh con nào nữa)
    color[u] = 2;
    return false;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> vertex >> edge;
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        memset(color, 0, sizeof(color));
        
        bool ok = false;
        for (int i = 1; i <= vertex; ++i) {
            if(!color[i]) {
                if(DFS(i)) {
                    ok = true;
                    break;
                }
            }
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}