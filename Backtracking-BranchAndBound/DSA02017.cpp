#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int a[10][10];
int ans = 0, n;
int x[10];
bool col[10], chinh[50], phu[50];

void Try(int i, int curSum) {
    for (int j = 1; j <= 8; ++j) {
        if(!col[j] && !chinh[n - j + i] && !phu[i + j - 1]) {
            x[i] = j;
            col[j] = true; chinh[n - j + i] = true; phu[i + j - 1] = true;
            curSum += a[i][x[i]];
            
            if(i == 8) ans = max(ans, curSum);
            else Try(i + 1, curSum);

            col[j] = false; chinh[n - j + i] = false; phu[i + j - 1] = false;
            curSum -= a[i][x[i]];
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    n = 8;
    while(test--) {
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) cin >> a[i][j]; 
        }
        Try(1, 0);
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}