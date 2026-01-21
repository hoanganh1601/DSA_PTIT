#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, a[22];
vector<int> res;
vector<string> listRes;

void Try(int i, int lastVal) {
    if(i == n + 1) {
        if(res.size() > 1) {
            string tmp = "";
            int len = res.size();
            for (int i = 0; i < len; ++i) {
                tmp += to_string(res[i]);
                if(i != len - 1) tmp += " ";
            }
            listRes.pb(tmp);
        }
        return;
    }

    // pick
    if(a[i] > lastVal){
        res.pb(a[i]);
        Try(i + 1, a[i]);
        res.pob();
    }

    // not pick
    Try(i + 1, lastVal);
}

signed main(){

    speed;  

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    res.reserve(n);

    Try(1, a[0]);

    sort(listRes.begin(), listRes.end());
    for (string x : listRes) {
        cout << x << endl;
    }

    return 0;
}