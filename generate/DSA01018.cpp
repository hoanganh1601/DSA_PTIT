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
int a[1002];

void generate() {

    int i = k;
    while(i >= 1 && a[i] == a[i - 1] + 1) {
        --i;    
    }
    
    if(i == 0) {
        for (int j = 1; j <= k; ++j) cout << n - k + j << " ";
    }
    else {

        --a[i];
        for (int j = i + 1; j <= k; ++j) a[j] = n - k + j;

        for (int j = 1; j <= k; ++j) cout << a[j] << " ";
    }
    cout << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    a[0] = 0;
    while(test--) {

        cin >> n >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i];

        generate();
    }

    return 0;
}