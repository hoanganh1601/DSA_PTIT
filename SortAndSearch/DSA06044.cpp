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

    int n; cin >> n;
    int a[n + 1]; 

    vector<int> odd, even;
    odd.reserve(n); even.reserve(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(i % 2 == 1) odd.pb(a[i]);
        else even.pb(a[i]);
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());

    int it1 = 0, it2 = 0;
    for (int i = 1; i <= n; ++i) {
        if(i % 2 == 1) cout << odd[it1++] << " ";
        else cout << even[it2++] << " ";
    }

    return 0;
}