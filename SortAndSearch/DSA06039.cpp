#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int a[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }   

    int check = 0;
    for (int i = 0; i < n; ++i) {
        if(mp[a[i]] != 1) {
            cout << a[i] << endl;
            check = 1;
            break;
        }
    }

    if(!check) cout << "NO" << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

        solve(a, n);
    }

    return 0;
}