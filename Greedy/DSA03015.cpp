#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        int n, s, m;
        cin >> n >> s >> m;

        if(n < m) {
            cout << -1 << endl;
            continue;
        }

        // ans : số ngày cần mua lương thực
        int ans = (s * m + n - 1) / n;

        // Because of without Sunday
        // How many days can you buy? 
        s = s - s / 7;

        if(ans > s) cout << -1 << endl;
        else cout << ans << endl;
    }   

    return 0;
}