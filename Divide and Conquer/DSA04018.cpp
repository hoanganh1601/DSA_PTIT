#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int find(int a[], int n) {
    int left = 0, right = n - 1;
    int firstIdx = -1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == 1) {
            firstIdx = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    if(firstIdx == -1) return n;
    return firstIdx;
}

signed main(){

    speed;  

    int test;
    cin >> test;

    int n;
    while(test--) {
        cin >> n;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

        // find one number
        cout << find(a, n) << endl;
    }   

    return 0;
}