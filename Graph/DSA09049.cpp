#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
const int MAXN = 200005;

vector<int> adj[MAXN];
long long sz[MAXN]; // Size of the subtree rooted at u
long long dp[MAXN]; // Total nutrient value at node u

void DFS(int u) {
    sz[u] = 1;
    dp[u] = 0;

    for (int v : adj[u]) {
        DFS(v);
        sz[u] += sz[v];
        dp[u] += dp[v]; 
    }

    dp[u] += sz[u];
}

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int par;
        cin >> par;
        adj[par].push_back(i);
    }

    DFS(1);

    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << " ";
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}