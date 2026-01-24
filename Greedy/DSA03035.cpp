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

    int n;
    cin >> n;
    int a[n]; 
    int dp[n] = {0}; // độ dài của dãy con liên tiếp tại vị trí i

    int res = 0; // độ dài dãy con liên tiếp lớn nhất
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        dp[a[i]] = dp[a[i] - 1] + 1; // connect
        
        res = max(res, dp[a[i]]);
    }

    cout << n - res << endl;

    return 0;
}