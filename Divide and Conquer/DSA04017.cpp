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
        int a[n], res = -1;
        for (int i = 0; i < n; ++i) cin >> a[i];

        int x;
        for (int i = 0; i < n - 1; ++i) {
            cin >> x;
            if(x != a[i] && res == -1) res = i + 1;
        }

        cout << res << endl;
    }   

    return 0;
}