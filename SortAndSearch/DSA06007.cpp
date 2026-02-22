#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);

        int left = 0, right = n - 1;
        while(left < right) {
            if(a[left] == b[left]) ++left;
            if(a[right] == b[right]) --right;
            
            if(a[left] != b[left] && a[right] != b[right]) break; 
        }

        cout << left + 1 << " " << right + 1 << endl;
    }

    return 0;
}