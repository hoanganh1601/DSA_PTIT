#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void init(int a[], int n) {for (int i = 0; i < n; ++i) cin >> a[i];}

signed main(){

    speed;  

    int test; cin >> test;
    int n, m, k;
    while(test--) {
        cin >> n >> m >> k;
        int a[n], b[m], c[k];
        init(a, n); init(b, m); init(c, k);

        int i = 0, j = 0, p = 0;
        // int cnt = 0;

        vector<int> res;
        res.reserve(n);

        while(i < n && j < m && p < k) {

            if(a[i] == b[j] && b[j] == c[p]) {
                res.pb(a[i]);
                ++i; ++j; ++p;
                continue;
            }

            int check = max(max(a[i], b[j]), c[p]);

            if(check != a[i]) ++i;
            if(check != b[j]) ++j;
            if(check != c[p]) ++p;
        }

        if(res.empty()) cout << "NO" << endl;
        else {
            for (int x : res) cout << x << " ";
            cout << endl;
        }
    }   

    return 0;
}