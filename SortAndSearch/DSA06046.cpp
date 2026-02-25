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
    int n;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        int ans = LLONG_MAX;
        for (int i = 1; i < n; ++i) ans = min(ans, a[i] - a[i - 1]);
        cout << ans << endl;
    }   

    return 0;
}