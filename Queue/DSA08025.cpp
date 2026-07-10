#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int minKnightMoves(string start, string target) {
    int startX = start[0] - 'a', startY = start[1] - '1';
    int targetX = target[0] - 'a', targetY = target[1] - '1';
    
    // Base case: If the start and target are the same, 0 moves are needed
    if(startX == targetX && startY == targetY) return 0;

    queue<pair<int, int>> q;
    q.push({startX, startY});

    int dist[8][8]; 
    memset(dist, -1, sizeof(dist));
    dist[startX][startY] = 0; 

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;

        if(x == targetX && y == targetY) return dist[x][y];

        for (int k = 0; k < 8; ++k) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];

            if(isValid(nextX, nextY) && dist[nextX][nextY] == -1) {
                dist[nextX][nextY] = dist[x][y] + 1;
                q.push({nextX, nextY});
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        string start, target;
        cin >> start >> target;
        cout << minKnightMoves(start, target) << endl;
    }

    return 0;
}