#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9;

void solve() {
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int>> dist(vertex + 1, vector<int>(vertex + 1, INF));

    for (int i = 1; i <= vertex; ++i) dist[i][i] = 0;

    // Read directed edges
    for (int i = 0; i < edge; ++i) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1; 
    }

    for (int k = 1; k <= vertex; ++k) {
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    double totalSum = 0;
    int validCount = 0;

    // Sum all valid shortest paths between distinct pairs
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            if (i != j && dist[i][j] != INF) {
                totalSum += dist[i][j];
                validCount++;
            }
        }
    }

    if (validCount == 0) {
        cout << fixed << setprecision(2) << 0.00 << endl;
    } 
    else {
        cout << fixed << setprecision(2) << (totalSum / validCount) << endl;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; 
    if (cin >> test) {
        while (test--) {
            solve();
        }
    }

    return 0;
}