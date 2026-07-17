#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pii = pair<int, ii>;

const int INF = 1e9;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void solve() {
    int row, col; cin >> row >> col;
    int arr[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dist(row, vector<int>(col, INF));
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[0][0] = arr[0][0];
    pq.push({arr[0][0], {0, 0}});

    while(!pq.empty()) {
        pii cur = pq.top(); pq.pop();

        int d = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;

        if(d > dist[u][v]) continue;
        if(u == row - 1 && v == col - 1) continue;
    
        for (int k = 0; k < 4; ++k) {
            int nx = u + dx[k];
            int ny = v + dy[k];

            if(nx >= 0 && nx < row && ny >= 0 && ny < col) {
                if(dist[nx][ny] > dist[u][v] + arr[nx][ny]) {
                    dist[nx][ny] = dist[u][v] + arr[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }

    cout << dist[row - 1][col - 1] << endl;
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