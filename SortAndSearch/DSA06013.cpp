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
    int n, k; 
    while(test--) {
        cin >> n >> k;
        vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> :: iterator it1 = lower_bound(a.begin(), a.end(), k);
        vector<int> :: iterator it2 = upper_bound(a.begin(), a.end(), k);

        int ans = it2 - it1;
        if(ans == 0) ans = -1; // NOT FOUND

        cout << ans << endl;
    }

    return 0;
}