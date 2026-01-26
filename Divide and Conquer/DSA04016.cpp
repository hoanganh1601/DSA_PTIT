#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int find(int a[], int b[], int m, int n, int k) {
    int i = 0, j = 0;
    int cnt = 0;
    
    vector<int> v;
    v.reserve(n + m);
    while(i < m && j < n) {
        if(a[i] > b[j]) v.pb(b[j++]);
        else if(a[i] < b[j]) v.pb(a[i++]);
        else {
            v.pb(a[i++]);
        }

        if(v.size() == k) return v[k - 1];
    }

    while(i < m) {
        v.pb(a[i++]);
        if(v.size() == k) return v[k - 1];
    }

    while(j < m) {
        v.pb(b[j++]);
        if(v.size() == k) return v[k - 1];
    }
} 

signed main(){

    speed;  

    int test; 
    cin >> test;
    int m, n, k;
    while(test--) {
        cin >> m >> n >> k;
        int a[m], b[n];
        for (int i = 0; i < m; ++i) cin >> a[i];
        for (int j = 0; j < n; ++j) cin >> b[j];

        cout << find(a, b, m, n, k) << endl;
    }   

    return 0;
}