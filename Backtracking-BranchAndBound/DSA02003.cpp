#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int mat[12][12];
int n;
string res;
vector<string> listRes;

void Try(int i, int j) {
    // cout << 1 << " ";
    if(i == n && j == n) {
        listRes.pb(res);
        return;
    }

    // Down
    if(i + 1 <= n && mat[i + 1][j] == 1) {
        mat[i + 1][j] = 0;
        res.pb('D');
        Try(i + 1, j);
        res.pob();
        mat[i + 1][j] = 1;
    }

    // Right
    if(j + 1 <= n && mat[i][j + 1] == 1) {
        mat[i][j + 1] = 0;
        res.pb('R');
        Try(i, j + 1);
        res.pob();
        mat[i][j + 1] = 1;
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cin >> mat[i][j];
        }

        listRes.clear();
        res = "";

        if(mat[1][1] == 0 || mat[n][n] == 0) cout << -1 << endl;
        else {

            Try(1, 1);

            if(listRes.empty()) cout << -1 << endl;
            else {
                int len = listRes.size();
                for (int i = 0; i < len; ++i) {
                    cout << listRes[i] << " ";
                } 
                cout << endl;
            }
        }
    }

    return 0;
}