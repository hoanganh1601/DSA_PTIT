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
int a[17];

void generate() {
    int cnt = 0;
    while(1) {
        ++cnt;
        int i = k;
        while(i >= 1 && a[i] == a[i - 1] + 1) --i;
        if(i == 0) {
            cout << cnt << endl;
            return;
        }
        else {
            --a[i];
            for (int j = i + 1; j <= k; ++j) a[j] = n - k + j;
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;

    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i];
        generate();
    }

    return 0;
}