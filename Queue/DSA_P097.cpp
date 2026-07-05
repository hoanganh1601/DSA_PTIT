#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

// The 8 possible directions the robot can move
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Pack two 32-bit integers (x, y) into one 64-bit integer
inline long long encode(int x, int y) {
    return (1LL * x << 32) | (unsigned int)y;
}

void solve() {
    int xA, yA, xB, yB;
    cin >> xA >> yA >> xB >> yB;

    int n; cin >> n;

    unordered_set<ll> valid_cells;
    valid_cells.reserve(100000);

    for (int i = 0; i < n; i++) {
        int x, y1, y2;
        cin >> x >> y1 >> y2;

        for (int y = y1; y <= y2; y++) {
            valid_cells.insert({encode(x, y)});
        }
    }

    // Queue stores: {{current_x, current_y}, current_steps}
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{xA, yA}, 0});
    valid_cells.erase(encode(xA, yA)); 

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int cx = current.first.first;
        int cy = current.first.second;
        int steps = current.second;

        // Reached the destination
        if (cx == xB && cy == yB) {
            cout << steps << endl;
            return;
        }

        // Explore all 8 neighbors
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            long long encoded_pos = encode(nx, ny);

            if (valid_cells.count(encoded_pos)) {
                q.push({{nx, ny}, steps + 1});
                valid_cells.erase(encoded_pos);
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