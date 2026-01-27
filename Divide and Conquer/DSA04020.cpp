#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int search(int a[], int n, int k) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == k) return mid + 1;
        else if(a[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        
        int check = search(a, n, k);
        if(check == -1) cout << "NO" << endl;
        else cout << check << endl;
    }   

    return 0;
}