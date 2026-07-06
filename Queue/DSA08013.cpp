#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solve() {
    int n; cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; ++i) cin >> grid[i];

    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    // Edge case: Start and End are the exact same point
    if (startX == endX && startY == endY) return 0;


    vector<vector<int>> dist(n, vector<int>(n, - 1));
    queue<pair<int, int>> q;

    q.push({startX, startY});
    dist[startX][startY] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == endX && y == endY) return dist[x][y];

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.') {
                if(dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }

                // Continue moving in the same direction
                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    return -1;
}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cout << solve() << endl;
    }

    return 0;
}