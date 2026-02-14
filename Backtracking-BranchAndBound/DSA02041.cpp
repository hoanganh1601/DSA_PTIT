#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int ans;

void Try(int n, int cnt) {

    // branchAndBound
    if(cnt >= ans) return;

    if(n == 1) {
        ans = min(ans, cnt);
        return;
    }
    
    if(n % 3 == 0) {
        Try(n / 3, cnt + 1);
    }

    if(n % 2 == 0) {
        Try(n / 2, cnt + 1);
    }

    Try(n - 1, cnt + 1);
}

signed main(){

    speed;  

    int test;
    cin >> test;

    int n;
    while(test--) {
        cin >> n;
        ans = n;
        Try(n, 0);
        cout << ans << endl;
    }   

    return 0;
}