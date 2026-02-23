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

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        map<int, int> mp;
        int a[n]; 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(mp.find(a[i]) == mp.end()) mp[a[i]] = i;
        }

        vector<pair<int, int>> listRes(mp.begin(), mp.end());
        // for (auto x : listRes) {
        //     cout << x.fi << " " << x.se << endl;
        // }
        // sort(listRes.begin(), listRes.end());

        int ans = -1;
        int minValue = listRes[0].se;
        for (int i = 1; i < listRes.size(); ++i) {
            if(listRes[i].se > minValue) {
                ans = max(ans, listRes[i].se - minValue);
            }
            else minValue = listRes[i].se;
        }

        cout << ans << endl;
    }

    return 0;
}