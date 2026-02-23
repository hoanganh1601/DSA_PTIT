#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(vector<int> res) {
    int len = res.size();

    vector<vector<int>> listRes;
    listRes.reserve(len - 1);
    for (int i = 0; i < len; ++i) {
        int pos = i - 1, tmp = res[i];
        while(pos >= 0 && tmp < res[pos]) {
            res[pos + 1] = res[pos];
            --pos;
        }        
        res[++pos] = tmp;

        listRes.pb(res);
    }

    for (int i = len - 1; i >= 0; --i) {
        cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; ++j) {
            cout << listRes[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){

    speed;  

    int test = 1; 
    // cin >>  test;
    int n;
    while(test--) {
        cin >> n;
        vector<int> a(n); for (int &x : a) cin >> x;

        solve(a);
    }   

    return 0;
}