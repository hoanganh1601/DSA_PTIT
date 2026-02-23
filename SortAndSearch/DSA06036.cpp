#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int a[], int n, int k) {
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1, right = n - 1;

        while(left < right) {
            int valueLeft = a[left], valueRight = a[right];
            int sum = a[left] + a[right] + a[i];
            if(sum == k) {
                int cntLeft = 0, cntRight = 0;
                while(a[left] == valueLeft) {
                    ++left;
                    ++cntLeft;
                }

                while(a[right] == valueRight) {
                    ++right;
                    ++cntRight;
                }

                ans += cntLeft * cntRight;
            }
            else if(sum > k) --right;
            else ++left; 
        }
    }

    if(!ans) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        solve(a, n, k);
    }   

    return 0;
}