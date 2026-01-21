#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int row, col;
int a[101][101];

int ans = 0;

void Try(int i, int j) {
    if(i == row && j == col) {
        ++ans;
        return;
    }

    if(i + 1 <= row) Try(i + 1, j);
    if(j + 1 <= col) Try(i, j + 1);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> row >> col;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) cin >> a[i][j];
        }
        Try(1, 1);
        cout << ans << endl;
        ans = 0;
    }   

    return 0;
}