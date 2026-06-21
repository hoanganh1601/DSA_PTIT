#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int vertex, edge;
bool vs[15];
vector<int> adj[15];
bool ok;

void Try(int u, int cnt) {
    if(ok) return;
    if(cnt + 1 == vertex) {
        ok = true;
        return;
    }

    for (int v : adj[u]) {
        if(!vs[v]) {
            vs[v] = true;
            Try(v, cnt + 1);
            vs[v] = false;
        }
    }
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
            adj[v].push_back(u);
        }
        
        for (int i = 1; i <= vertex; ++i) {
            ok = false;
            memset(vs, false, sizeof(vs));

            vs[i] = true; // important
            Try(i, 0);
            if(ok) break;
        }
        
        cout << ok << endl;

        for (int i = 1; i <= vertex; ++i) adj[i].clear();
    }

    return 0;
}