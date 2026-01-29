#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

struct Cell {
    int row, col, status;
};

void solve(int m, int n) {
    int a[m + 1][n + 1];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    queue<Cell> q;
    q.push({1, 1, 0});
    vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));    
    visited[1][1] = true;

    while(!q.empty()) {
        Cell x = q.front(); q.pop();

        // cout << x.row << " " << x.col << endl;
        if(x.row == m && x.col == n) {
            cout << x.status << endl;
            return;
        }

        int k = a[x.row][x.col]; 

        if(x.row + k <= m && !visited[x.row + k][x.col]) {
            visited[x.row + k][x.col] = true;
            q.push({x.row + k, x.col, x.status + 1});
        }

        if(x.col + k <= n && !visited[x.row][x.col + k]) {
            visited[x.row][x.col + k] = true;
            q.push({x.row, x.col + k, x.status + 1});
        }
    }

    cout << -1 << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    int m, n;
    while(test--) {
        cin >> m >> n;
        solve(m, n);
    }   

    return 0;
}