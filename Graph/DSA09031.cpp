#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int N, K, M;
bool has_sheep[105][105];
bool visited[105][105];

// store both directions: (u, v) -> (x, y) and (x, y) -> (u, v)
set<pair<ii, ii>> fences;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    
    int sheep_count = 0;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        int cx = curr.first;
        int cy = curr.second;
        
        if (has_sheep[cx][cy]) {
            sheep_count++;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                // A fence blocking the path
                if (fences.count({{cx, cy}, {nx, ny}}) == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return sheep_count;
}

void solve() {
    
    cin >> N >> K >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        fences.insert({{u, v}, {x, y}});
        fences.insert({{x, y}, {u, v}});
    }
    
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        has_sheep[x][y] = true;
    }
    
    ll total = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                // Get the number of sheep in this reachable area
                int sheep_in_component = bfs(i, j);
                
                // separated from the rest
                if (sheep_in_component > 0) {
                    total += 1LL * sheep_in_component * (K - sheep_in_component);
                }
            }
        }
    }
    
    // Counted twice (A separated from B, and B separated from A)
    cout << total / 2 << endl;
}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}