#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int col, row;
int arr[501][501];
bool visited[501][501];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j) {
    visited[i][j] = true;

    for (int k = 0; k < 8; ++k) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if(i1 >= 1 && i1 <= row && j1 >= 1 && j1 <= col && arr[i][j] == 1 && !visited[i1][j1]) {
            DFS(i1, j1);
        }
    }
}

void solve() {
    cin >> row >> col;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) cin >> arr[i][j];
    }

    // tplt
    int cnt = 0;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if(arr[i][j] == 1 && !visited[i][j]) {
                ++cnt;
                DFS(i, j);
            }
        }
    }
    
    cout << cnt << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}