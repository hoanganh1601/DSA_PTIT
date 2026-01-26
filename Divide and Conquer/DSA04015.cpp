#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int floor(int a[], int n, int x) {
    int left = 1, right = n - 1;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] <= x) {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    return ans;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n, x;
    while(test--) {
        cin >> n >> x;
        int a[n + 1]; for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << floor(a, n + 1, x) << endl;
    }

    return 0;
}