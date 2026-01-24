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
    int n, start, end;
    while(test--) {
        cin >> n;
        int q = n;

        // first: end, second: start
        vector<pair<int, int>> listTime;
        while(q--) {
            cin >> start >> end;
            listTime.pb({end, start});
        }

        sort(listTime.begin(), listTime.end());

        int cnt = 1;
        int curEndTime = listTime[0].fi;

        for (int i = 1; i < n; ++i) {
            if(listTime[i].se >= curEndTime) {
                ++cnt;
                curEndTime = listTime[i].fi;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}