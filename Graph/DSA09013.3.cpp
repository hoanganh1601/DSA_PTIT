#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex, edge;
vector<int> adj[1005];
int id[1005]; // thứ tự thăm của u trong DFS
int low[1005]; // đỉnh thấp nhất mà đỉnh v có thể đến
int cnt;
vector<pair<int, int>> res;

// p: parent
void DFS(int u, int p) {
    low[u] = id[u] = ++cnt;

    for (int v : adj[u]) {
        // chống đi ngược lại con đường 2 chiều vừa đi!
        // Không xét lại cạnh (u, v) nếu nó chính là (parent, u)
        if(v == p) continue;

        // Đỉnh v đã được thăm chưa
        if(id[v]) {
            // Nếu đã được thăm thì đây chính là backward edge
            low[u] = min(low[u], id[v]);
        }
        else {
            // v chưa thăm, duyệt xuống dưới
            DFS(v, u);

            // Sau khi v duyệt xong, u thừa hưởng lại khả năng vươn lên của v 
            low[u] = min(low[u], low[v]);
        }

        // chung to co canh nguoc (duong di khac neu xoa di)
        // low[v] <= id[u] : Không có cạnh cầu do 

        if(low[v] > id[u]) {
            res.push_back({min(u, v), max(u, v)});
        }
    }
}

void solve() {
    cin >> vertex >> edge;

    // reset data
    for (int i = 1; i <= vertex; ++i) {
        id[i] = 0; low[i] = 0;
        adj[i].clear();
    }
    res.clear();
    cnt = 0;

    for (int i = 1; i <= edge; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    for (int i = 1; i <= vertex; ++i) {
        if(!id[i]) {
            DFS(i, -1); // Bắt đầu DFS mới
        }
    }

    sort(res.begin(), res.end());

    for (pair<int, int> x : res) {
        cout << x.first << " " << x.second << " ";
    }
    cout << endl;
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