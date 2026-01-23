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
    
    string s;
    while(test--) {
        cin >> s;
        unordered_map<char, int> mp;
        for (int i = 0; s[i]; ++i) {
            mp[s[i]]++;
        }

        int maxx = -1;
        for (pair<int, int> x : mp) {
            maxx = max(maxx, x.se);
        }

        if(maxx <= (s.size() + 1) / 2) cout << 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}