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
    int n, target;
    while(test--) {
        cin >> n >> target;
        unordered_map<int, int> mp;
        int x; 
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            cin >> x;

            int k = target - x;
            if(mp[k] != 0) {
                ans += mp[k]; 
            }

            mp[x]++;
        } 
        
        cout << ans << endl;
    }    

    return 0;
}