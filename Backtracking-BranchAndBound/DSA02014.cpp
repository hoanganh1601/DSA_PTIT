// Author: Lê Hoàng Anh
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int num_words, row, col;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool vs[100][100];
string dict[100];
vector<string> res;
char arr[100][100];

void dfs(int u, int v, string s) {
    // the current string matches any word in the dictionary
    for (int i = 0; i < num_words; ++i) {
        if (dict[i] == s) {
            res.push_back(s);
        }
    }
    
    // Explore all 8 adjacent directions
    for (int i = 0; i < 8; ++i) {
        int nu = u + dx[i];
        int nv = v + dy[i];
        
        if (nu >= 0 && nu < row && nv >= 0 && nv < col && !vs[nu][nv]) {
            vs[nu][nv] = true;
            dfs(nu, nv, s + arr[nu][nv]);
            vs[nu][nv] = false; 
        }
    }
}

void solve() {
    res.clear();
    cin >> num_words >> row >> col;
    
    for (int i = 0; i < num_words; ++i) {
        cin >> dict[i];
    }
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            memset(vs, false, sizeof(vs));
            vs[i][j] = true;
            string start = "";
            start += arr[i][j];
            
            dfs(i, j, start);
        }
    }
    
    if (res.empty()) {
        cout << -1 << endl;
    } 
    else {
        for (string tmp : res) {
            cout << tmp << " ";
        }
        cout << endl;
    }
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
