#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int a[], int n, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = k - a[i];
        if(mp.find(tmp) != mp.end()) {
            ans += mp[tmp];
        }

        mp[a[i]]++;
    }
    cout << ans << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

        solve(a, n, k);
    }

    return 0;
}