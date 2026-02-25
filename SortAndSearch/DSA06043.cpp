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
    int prefix[n];
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + a[i];

    bool check = false;
    for (int i = 1; i < n - 1; ++i) {
        if(prefix[i] == prefix[n - 1] - prefix[i - 1]) {
            cout << i + 1 << " ";
            check = true;
            break;
        }
    }
    if(!check) cout << -1;
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