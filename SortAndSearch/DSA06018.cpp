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
        int a[100005]; 
        int maxElement = LLONG_MIN, minElement = LLONG_MAX;
        int mark[100005]; memset(mark, 0, sizeof(mark));

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mark[a[i]] = 1;
            maxElement = max(maxElement, a[i]);
            minElement = min(minElement, a[i]);
        }

        int ans = 0;
        for (int i = minElement; i <= maxElement; ++i) {
            if(!mark[i]) ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}