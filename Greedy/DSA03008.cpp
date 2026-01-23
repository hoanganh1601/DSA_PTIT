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
        int x;
        // first: endTime, second: startTime
        vector<pair<int, int>> listRes(n);

        for (int i = 0; i < n; ++i) {
            cin >> x;
            listRes[i].se = x;
        }
        for (int i = 0; i < n; ++i) {
            cin >> x; 
            listRes[i].fi = x;
        }

        sort(listRes.begin(), listRes.end());
        int ans = 1; // first work

        int end = listRes[0].fi;
        for (int i = 1; i < n; ++i) {
            if(listRes[i].se >= end) {
                ++ans;
                end = listRes[i].fi;
            }
        }

        cout << ans << endl;
    }

    return 0;
}