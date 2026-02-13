#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int a[16], n;
vector<int> tmp;
vector<vector<int>> listRes;

void Try(int start, int curSum) {
    if(curSum % 2 == 1) {
        listRes.pb(tmp);
    }

    if(start > n) return;

    for (int j = start; j <= n; ++j) {
        tmp.pb(a[j]);
        Try(j + 1, curSum + a[j]);
        tmp.pob();
    }
}

signed main(){

    speed;  

    int test; 
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        sort(a + 1, a + 1 + n, greater<int>());

        Try(1, 0);
        sort(listRes.begin(), listRes.end());

        for (vector<int> x : listRes) {
            for (int y : x) cout << y << " ";
            cout << endl;
        }
        listRes.clear();
    }   

    return 0;
}