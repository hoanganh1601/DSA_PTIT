#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int k, n, m;
vector<int> startPos;
vector<vector<int>> adj;

int reachCnt[1005];
int vs[1005];

void dfs(int u) {
    vs[u] = true;
    reachCnt[u]++; 
    
    for (int v : adj[u]) {
        if (!vs[v]) {
            dfs(v);
        }
    }
}

void solve() {
    cin >> k >> n >> m;
    startPos.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> startPos[i];
    }

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
    }

    memset(reachCnt, 0, sizeof(reachCnt));

    for (int i = 0; i < k; i++) {
        memset(vs, false, sizeof(vs));
        dfs(startPos[i]);
    }

    int valid = 0;
    for (int i = 1; i <= n; i++) {
        if (reachCnt[i] == k) {
            ++valid;
        }
    }

    cout << valid;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}