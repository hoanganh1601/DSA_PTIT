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
int a[102];
vector<int> num;

bool check = false;

void Try(int i, int curSum) {
    if(i > n) {
        if(curSum == k) {
            check = true;
            int len = num.size();
            cout << "[";
            for (int i = 0; i < len; ++i) {
                cout << num[i];
                if(i != len - 1) cout << " ";
            } 
            cout << "] "; 
        }
        return;
    }

    // pick
    if(a[i] + curSum <= k) {
        num.pb(a[i]);
        Try(i + 1, curSum + a[i]);
        num.pob();
    }

    // not pick
    Try(i + 1, curSum);
}

signed main(){

    speed;  

    int test; cin >> test;
    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        sort(a + 1, a + 1 + n);
        num.reserve(n + 1);
        Try(1, 0);
        if(!check) cout << -1 << endl;
        check = false;
        // num.clear();
        cout << endl;
    }

    return 0;
}