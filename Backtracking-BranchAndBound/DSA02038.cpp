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
int a[16];
int val[16];

void Try(int i, int start) {
    for (int j = start; j <= n; ++j) {
        val[i] = a[j];
        if(i == k) {
            for (int p = 1; p <= k; ++p) {
                cout << val[p] << " ";
            }
            cout << endl;
        }
        else Try(i + 1, j + 1);
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);

        Try(1, 1);
    }    

    return 0;
}