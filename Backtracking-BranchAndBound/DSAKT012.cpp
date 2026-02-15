#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, S;
int cost[32];
int suffix[32];
int ans = LLONG_MAX;

void Try(int i, int curSum, int quantity) {
    if(curSum == S) {
        ans = min(ans, quantity);
        return;
    }

    if(quantity >= ans) return;
    if(i > n) return;
    if(curSum > S) return;

    if(curSum + suffix[i] < S) return;

    // pick
    Try(i + 1, curSum + cost[i], quantity + 1);

    // not pick
    if(curSum + suffix[i + 1] >= S) {
        Try(i + 1, curSum, quantity);
    }
}

signed main(){

    speed;  

    cin >> n >> S;
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    sort(cost + 1, cost + 1 + n, greater<int>());

    suffix[n] = cost[n];
    for (int i = n - 1; i >= 1; --i) {
        suffix[i] = suffix[i + 1] + cost[i];
    }

    Try(1, 0, 0);

    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;

    return 0;
}