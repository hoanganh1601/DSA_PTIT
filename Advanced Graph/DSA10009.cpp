#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
const int INF = (int)1e9;

int vertex, edge, q;
vector<vector<int>> d(105, vector<int>(105, INF));
// int par[105][105];

int main() {

    cin >> vertex >> edge;

    // base case: IMPORTANT
    for (int i = 1; i <= vertex; ++i) {
        d[i][i] = 0;
    }

    for (int i = 1; i <= edge; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        // In case of multiple edges between the same nodes
        d[u][v] = min(d[u][v], weight);
        d[v][u] = min(d[v][u], weight);
    }

    for (int k = 1; k <= vertex; ++k) {
        for (int i = 1; i <= vertex ; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    d[j][i] = d[i][j];
                    // // par[i][j] = par[k][j];
                }
            }
        }
    }

    cin >> q;

    while(q--) {
        int s, t; cin >> s >> t;
        cout << d[s][t] << endl;
    }

    return 0;
}