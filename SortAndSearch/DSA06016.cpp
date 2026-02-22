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
    int n, m; 
    while(test--) {
        cin >> n >> m;
        int a[n], b[m]; 
        int maxOfA = LLONG_MIN, minOfB = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            maxOfA = max(maxOfA, a[i]);
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            minOfB = min(minOfB, b[i]);
        }

        cout << maxOfA * minOfB << endl;
    }

    return 0;
}