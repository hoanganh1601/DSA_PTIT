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
vector<string> res, a;

void display() {
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int i, int start) {
    for (int j = start + 1; j <= n - k + i; ++j) {
        res.pb(a[j]);

        if(i == k) display();
        else Try(i + 1, j);
        res.pob();
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    set<string> se;
    string tmp;
    for (int i = 1; i <= n; ++i) {cin >> tmp; se.insert(tmp);}
  
    n = se.size();
    res.reserve(n + 1), a.reserve(n + 1);

    res.pb("0");
    a.pb("0");

    for (string x : se) {
        a.pb(x);
    }

    Try(1, 0);

    return 0;
}