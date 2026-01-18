#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, k, ans = 0;
vector<int> res;
vector<int> num;

void Try(int i, int curSum) {

    if(i > n) {
        if(curSum == k) ++ans;
        return;
    }

    // pick
    if(curSum + res[i] <= k) Try(i + 1, curSum + res[i]);

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
    cout << ans << endl;

    return 0;
}