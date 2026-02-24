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
    int len = n / 2;
    bool check = false;
    for (pair<int, int> x : mp) {
        if(x.se > len) {
            cout << x.fi;
            check = true;
            break;
        }
    }
    if(!check) cout << "NO";
    cout << endl;
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