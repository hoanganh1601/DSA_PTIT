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
    for (int i = 0; i < len - 1; ++i) {
        int pos = i;
        for (int j = i + 1; j < len; ++j) {
            if(res[j] < res[pos]) pos = j;
        }
        swap(res[pos], res[i]);

        listRes.pb(res);
    }

    int cnt = len - 1;
    for (int i = len - 2; i >= 0; --i) {
        cout << "Buoc " << cnt-- << ": ";
        for (int x : listRes[i]) {
            cout << x << " ";
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