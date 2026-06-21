#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int par[1005], sz[1000005];
int n;

void init() {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool Union(int u, int v) {
    u = find(u); v = find(v);
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

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        init();
        
        bool ok = true;
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            if(!Union(u, v)) {
                ok = false;
            }
        }
    
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}