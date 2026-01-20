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

int ans = 0;

void Try(int lastIdx, int curLen) {
    for (int j = lastIdx + 1; j <= n; ++j) {
        if(a[lastIdx] < a[j]) {         
            if(curLen == k) {
                ++ans;
            }
            else Try(j, curLen + 1);
        }
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    // Lấy phần tử đầu tiên, first = 0
    Try(0, 1);

    cout << ans;

    return 0;
}