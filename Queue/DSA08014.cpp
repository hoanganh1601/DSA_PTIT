#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Cell {
    int r, c, day;
};

int row, col;
int grid[505][505];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void BFS() {
    queue<Cell> q;
    int unsprouted = 0;

    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if(grid[i][j] == 2) {
                // Push all initial seedlings into the queue at day 0
                q.push({i, j, 0});
            }
            else if(grid[i][j] == 1) ++unsprouted;
        }
    }

    int maxDays = 0; // component

    while(!q.empty()) {
        Cell cur = q.front(); q.pop();
        maxDays = max(maxDays, cur.day);

        for (int i = 0; i < 4; ++i) {
            int nx = cur.r + dx[i], ny = cur.c + dy[i];
            if(nx >= 1 && nx <= row && ny >= 1 && ny <= col && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                --unsprouted;
                q.push({nx, ny, cur.day + 1});
            }
        }
    }

    if(unsprouted > 0) cout << -1 << endl;
    else cout << maxDays << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> row >> col;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) cin >> grid[i][j];
        }

        BFS();
    }

    return 0;
}