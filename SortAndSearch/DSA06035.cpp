#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int a[], int n) {
    int up[n], down[n];
    up[0] = 1;

    // đề bài sai: Tăng và giảm ngặt mới đúng
    for (int i = 1; i < n; ++i) {
        if(a[i] > a[i - 1]) up[i] = up[i - 1] + 1;
        else up[i] = 1;
    }

    down[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if(a[i] > a[i + 1]) down[i] = down[i + 1] + 1;
        else down[i] = 1; 
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << up[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i) cout << down[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, up[i] + down[i] - 1);
    }

    cout << ans << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        solve(a, n);
    }   

    return 0;
}