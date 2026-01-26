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
    int n, a[101];
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        int sum = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }   

    return 0;
}