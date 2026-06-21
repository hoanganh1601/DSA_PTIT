#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int row, col;
pair<int, int> s, t;
char x[505][505];
int cnt[505][505];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool ok;

void BFS(int u, int v) {
    queue<ii> q;
    q.push({u, v});
    cnt[u][v] = 0;

    while(!q.empty()) {
        ii cur = q.front(); q.pop();
        int i = cur.first, j = cur.second;
        
        if(cnt[i][j] == 3) continue; // tối đa là 2, không cho đi nữa

        for (int k = 0; k < 4; ++k) {
            int i1 = i + dx[k], j1 = j + dy[k];

            while(i1 >= 1 && i1 <= row && j1 >= 1 && j1 <= col && x[i1][j1] != '*') {
                if(x[i1][j1] == 'T')  {
                    ok = true;
                    return;
                }

                if(cnt[i1][j1] == -1) {
                    cnt[i1][j1] = cnt[i][j] + 1;
                    q.push({i1, j1});
                }

                i1 += dx[k];
                j1 += dy[k];
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> row >> col;
        for(int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                cin >> x[i][j];
                if(x[i][j] == 'S') s = {i, j};
                else if(x[i][j] == 'T') t = {i, j};
            }
        }

        ok = false;
        memset(cnt, -1, sizeof cnt);
        BFS(s.first, s.second);
 
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 
    return 0;
}