#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int k;
int cmp(int a, int b) {
    if(abs(a - k) != abs(b - k)) return abs(a - k) < abs(b - k);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n, x;
    while(test--) {
        cin >> n >> x;
        k = x;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        stable_sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}