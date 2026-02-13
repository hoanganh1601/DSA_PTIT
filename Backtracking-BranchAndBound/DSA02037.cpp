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

bool checkValid(int n){
    if(n < 2) return false;
    else if(n == 2 || n == 3) return true;
    else if(n % 2 == 0 || n % 3 == 0) return false;
    else {
        for (int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    } 
}

void Try(int start, int curSum) {
    if(checkValid(curSum)) {
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