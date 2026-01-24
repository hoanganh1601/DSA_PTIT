#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(string s, int d) {
    unordered_map<char, int> mp;

    for (int i = 0; s[i]; ++i) mp[s[i]]++;
 
    int maxx = -1;
    for (auto x : mp) {
        maxx = max(maxx, x.se);
    }

    // 0 + (maxx - 1) * D
    if((maxx - 1) * d < s.size()) cout << 1 << endl;
    else cout << -1 << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    int d;
    string s;
    while(test--) {
        cin >> d >> s;

        solve(s, d);
    }   

    return 0;
}