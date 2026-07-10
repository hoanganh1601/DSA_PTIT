#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MAX_GRID = 3010; 
bool is_fence[MAX_GRID][MAX_GRID];
bool visited[MAX_GRID][MAX_GRID];
bool has_cow[MAX_GRID][MAX_GRID];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Find the compressed index
int get_id(int val, const vector<int>& coords) {
    return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, pair<int, int>>> fences(n);
    vector<pair<int, int>> cows(m);
    vector<int> X_coords, Y_coords;

    // Read fences
    for (int i = 0; i < n; i++) {
        cin >> fences[i].first.first >> fences[i].first.second 
            >> fences[i].second.first >> fences[i].second.second;
        X_coords.push_back(fences[i].first.first);
        X_coords.push_back(fences[i].second.first);
        Y_coords.push_back(fences[i].first.second);
        Y_coords.push_back(fences[i].second.second);
    }


    for (int i = 0; i < m; i++) {
        cin >> cows[i].first >> cows[i].second;
        X_coords.push_back(cows[i].first);
        Y_coords.push_back(cows[i].second);
    }

    // Compress coordinates
    sort(X_coords.begin(), X_coords.end());
    X_coords.erase(unique(X_coords.begin(), X_coords.end()), X_coords.end());

    sort(Y_coords.begin(), Y_coords.end());
    Y_coords.erase(unique(Y_coords.begin(), Y_coords.end()), Y_coords.end());

    // Grid bounds (+4 to accommodate the scale-by-2 and the outer boundary padding)
    int W = X_coords.size() * 2 + 4;
    int H = Y_coords.size() * 2 + 4;

    // Reset grids for the current test case
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            is_fence[i][j] = false;
            visited[i][j] = false;
            has_cow[i][j] = false;
        }
    }

    // Draw fences on the grid
    for (int i = 0; i < n; i++) {
        // Multiply by 2 for spacing, add 2 for boundary padding
        int x1 = 2 * get_id(fences[i].first.first, X_coords) + 2;
        int y1 = 2 * get_id(fences[i].first.second, Y_coords) + 2;
        int x2 = 2 * get_id(fences[i].second.first, X_coords) + 2;
        int y2 = 2 * get_id(fences[i].second.second, Y_coords) + 2;

        if (x1 == x2) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) is_fence[x1][y] = true;
        } 
        else {
            for (int x = min(x1, x2); x <= max(x1, x2); x++) is_fence[x][y1] = true;
        }
    }

    // Place cows on the grid
    for (int i = 0; i < m; i++) {
        int cx = 2 * get_id(cows[i].first, X_coords) + 2;
        int cy = 2 * get_id(cows[i].second, Y_coords) + 2;
        has_cow[cx][cy] = true;
    }

    // Find max cows in one region (BFS)
    int max_cows = 0;
    
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            if (!visited[i][j] && !is_fence[i][j]) {
                int current_cows = 0;
                queue<pair<int, int>> q;
                
                q.push({i, j});
                visited[i][j] = true;
                
                while (!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    if (has_cow[cx][cy]) current_cows++;
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = cx + dx[d];
                        int ny = cy + dy[d];
                        
                        if (nx >= 0 && nx <= W && ny >= 0 && ny <= H) {
                            if (!visited[nx][ny] && !is_fence[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                max_cows = max(max_cows, current_cows);
            }
        }
    }
    
    cout << max_cows << endl;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}