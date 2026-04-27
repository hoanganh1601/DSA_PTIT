#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    int test;
    cin >> test;
    while(test--) {
        int vertex, edge;
        cin >> vertex >> edge;

        vector<vector<int>> adj(vertex + 1);
        for (int i = 0; i < edge; ++i) {
            int u, v; 
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= vertex; ++i) {
            cout << i << ": ";
            for (int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}