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

    int n;
    cin >> n;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    int max1 = max(a[0] * a[1], a[n - 1] * a[n - 2]);
    
    // a[0] * a[1] * a[n - 1]: two negative numbers * one largest positive number 
    int max2 = max(a[n - 1] * a[n - 2] * a[n - 3], a[0] * a[1] * a[n - 1]);
    


    cout << max(max1, max2);
    return 0;
}