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
        int x;
        map<int, int> mp; 
        for (int i = 0; i < n; ++i) {
            cin >> x;
            mp[x]++;
        }

        for (pair<int,int> x : mp) {
            for (int i = 0; i < x.se; ++i) cout << x.fi << " ";
        }
        cout << endl;
    }

    return 0;
}