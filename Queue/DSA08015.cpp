#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Point {
    int z, y, x, dist;
};

// Arrays to define the 6 possible movements in 3D space: 
// (Up, Down, Front, Back, Left, Right)
int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};

void solve() {
    int a, b, c; 
    cin >> a >> b >> c;

    vector<vector<string>> grid(a + 5, vector<string>(b + 5));
    Point start, end;

    for (int z = 1; z <= a; ++z) {
        for (int y = 1; y <= b; ++y) {
            string temp;
            cin >> temp;
            
            // Prepend a space to make the string 1-indexed!
            grid[z][y] = " " + temp;
            for (int x = 1; x <= c; ++x) {
                if (grid[z][y][x] == 'S') start = {z, y, x, 0};
                else if (grid[z][y][x] == 'E') end = {z, y, x, 0};
            }
        }
    }

    queue<Point> q;
    q.push(start);
    
    // Mark the starting point as visited by turning it into an obstacle
    grid[start.z][start.y][start.x] = '#';

    while(!q.empty()) {
        Point cur = q.front();
        q.pop();

        // If reached the destination
        if (cur.z == end.z && cur.y == end.y && cur.x == end.x) {
            cout << cur.dist << endl;
            return;
        }

        for (int i = 0; i < 6; ++i) {
            int nz = cur.z + dz[i];
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(nz >= 1 && nz <= a && ny >= 1 && ny <= b && nx >= 1 && nx <= c && grid[nz][ny][nx] != '#') {
                q.push({nz, ny, nx, cur.dist + 1});
                grid[nz][ny][nx] = '#'; // Mark as visited
            }
        }
    }

    cout << -1 << endl;
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