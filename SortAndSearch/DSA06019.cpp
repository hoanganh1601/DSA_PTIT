#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

// key: num, value: freq
int cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.se != p2.se) return p1.se > p2.se;
    return p1.fi < p2.fi;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        unordered_map<int, int> mp;
        int k;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            mp[k]++;
        } 

        vector<pair<int, int>> listRes(mp.begin(), mp.end());
        sort(listRes.begin(), listRes.end(), cmp);

        for (pair<int, int> num : listRes) {
            for (int i = 0; i < num.se; ++i) cout << num.fi << " ";
        }
        cout << endl;
    }   

    return 0;
}