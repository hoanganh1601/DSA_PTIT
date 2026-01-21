#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n; 
int a[12];

void Try(int i) {

    cout << "[";
    for (int j = 1; j <= i; ++j) {
        cout << a[j];
        if(j != i) cout << " ";
    }
    cout << "]" << endl;

    if(i == 1) return;

    for (int j = 1; j <= i - 1; ++j) {
        a[j] = a[j] + a[j + 1]; 
    }

    Try(i - 1);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        Try(n);
    }   

    return 0;
}