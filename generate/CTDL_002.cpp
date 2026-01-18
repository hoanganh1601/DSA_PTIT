#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, k;
vector<int> res, num;
vector<vector<int>> listNum;

void Try(int i, int curSum) {

    if(i > n) {
        if(curSum == k) {
            listNum.pb(num);
        }
        return;
    }

    // pick
    if(curSum + res[i] <= k) {
        num.pb(res[i]);
        Try(i + 1, curSum + res[i]);
        num.pob();
    }

    // not pick 
    Try(i + 1, curSum);
}

signed main(){

    speed;  

    cin >> n >> k;
    res.reserve(n + 1);
    res.pb(0);
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x; 
        res.pb(x);
    }

    Try(1, 0);

    int ans = listNum.size();
    if(!ans) cout << ans;
    else {
        for(int i = ans - 1; i >= 0; --i) {
            for (int j = 0; j < listNum[i].size(); ++j) {
                cout << listNum[i][j] << " ";   
            }
            cout << endl;
        }
        cout << ans;
    }

    return 0;
}