#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

ll n, S;
vector<ll> res;
ll suffix[32];
ll ans;

void Try(ll pos, ll curSum, ll curQuan) {
    
    if(curQuan >= ans) return;
    if(curSum == S) {
        ans = min(ans, curQuan);
        return;
    }

    if(pos == n) return;

    if(curSum + suffix[pos] >= S) {
        if(curSum + res[pos] <= S) Try(pos + 1, curSum + res[pos], curQuan + 1);
        Try(pos + 1, curSum, curQuan);
    }
}

void init() {

    res.clear();
    cin >> n >> S;
    res.reserve(n);
    int x;
    ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        res.push_back(x);
    } 

    sort(res.begin(), res.end(), greater<ll>());
    suffix[n - 1] = res[n - 1];
    for (int i = n - 2; i >= 0; --i) suffix[i] = suffix[i + 1] + res[i];

}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        
        init();
        
        Try(0, 0, 0);

        if(ans != LLONG_MAX) cout << ans;
        else cout << -1;

        cout << endl;
    }

    return 0;
}
