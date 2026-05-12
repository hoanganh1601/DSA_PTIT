#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int row, col;
char x[1001][1001];
bool visited[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void DFS(int i, int j) {

    visited[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if(i1 >= 1 && i1 <= row && j1 >= 1 && j1 <= col && x[i1][j1] == '#' && !visited[i1][j1]) {
            DFS(i1, j1);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> row >> col;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) cin >> x[i][j];
    }

    int cnt = 0;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if(x[i][j] == '#' && !visited[i][j]) {
                ++cnt;
                DFS(i, j);
            }
        }
    }

    cout << cnt;

    return 0;
}