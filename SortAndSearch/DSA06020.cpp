#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int binarySearch(int a[], int n, int target) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        // cout << mid << " ";
        if(a[mid] > target) right = mid - 1;
        else if(a[mid] < target) left = mid + 1;
        else return 1;
    }
    return -1; // NOT FOUND
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n, target;
    while(test--) {
        cin >> n >> target;
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
        cout << binarySearch(a, n, target) << endl;
    }   

    return 0;
}