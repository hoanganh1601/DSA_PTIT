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

    int test, n;
    cin >> test;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = LLONG_MAX;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if(abs(a[i] + a[j]) < abs(ans)) {
                    ans = a[i] + a[j];
                }
            }
        }

        cout << ans << endl;
    }   

    return 0;
}