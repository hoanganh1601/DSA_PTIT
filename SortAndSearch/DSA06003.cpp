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
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

        // Find the minimum element from index i + 1 to the end to swap 
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            int pos = i;
            for (int j = i + 1; j < n; ++j) {
                if(a[j] < a[pos]) {
                    pos = j;
                }
            }

            if(i != pos) {
                ++ans;
                swap(a[i], a[pos]);
            }
        }
        cout << ans << endl;
    }   

    return 0;
}