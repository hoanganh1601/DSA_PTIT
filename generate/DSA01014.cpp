#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, k, s;
int a[22];

int ans = 0;
int curSum;

void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) {
        a[i] = j;
        curSum += a[i];
        if(i == k) {
            if(curSum == s) ++ans;
        }
        else Try(i + 1);

        curSum -= a[i];
    }
}

signed main(){

    speed;  

    a[0] = 0;

    while(cin >> n >> k >> s) {
        if(n == 0 && k == 0 && s == 0) return 0;
        
        curSum = 0;
        if(n < k) {cout << 0 << endl; continue;}
        
        Try(1);
        cout << ans << endl;

        ans = 0;
    }

    return 0;
}