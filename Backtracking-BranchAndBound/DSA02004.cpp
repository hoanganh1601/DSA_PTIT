#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n;
int a[10][10];
string res;
vector<string> listRes; 

void Try(int i, int j) {
    if(i == n && j == n) {
        listRes.pb(res);
        return;
    }

    // down
    if(i + 1 <= n && a[i + 1][j] == 1) {
        res.pb('D');
        a[i + 1][j] = 0;
        Try(i + 1, j);
        a[i + 1][j] = 1;
        res.pob();
    }

    // right
    if(j + 1 <= n && a[i][j + 1] == 1) {
        res.pb('R');
        a[i][j + 1] = 0;
        Try(i, j + 1);
        a[i][j + 1] = 1;
        res.pob();
    }

    // up
    if(i >= 2 && a[i - 1][j] == 1) {
        res.pb('U');
        a[i - 1][j] = 0;
        Try(i - 1, j);
        a[i - 1][j] = 1;
        res.pob();
    }

    // left
    if(j >= 2 && a[i][j - 1] == 1) {
        res.pb('L');
        a[i][j - 1] = 0;
        Try(i, j - 1);
        a[i][j - 1] = 1;
        res.pob();
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) cin >> a[i][j];
        }

        if(a[1][1] == 0 || a[n][n] == 0) cout << -1 << endl;
        else {

            a[1][1] = 0;

            Try(1, 1);

            if(listRes.empty()) cout << -1 << endl;
            else {
                sort(listRes.begin(), listRes.end());
                for (string x : listRes) cout << x << " ";
                cout << endl;
            }
        }   

        res = "";
        listRes.clear();
    }

    return 0;
}