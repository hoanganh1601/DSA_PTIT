#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

const int MOD = 123456789;

int power(int a, int b) {
    if(b == 0 || a == 1) return 1;
    int tmp = power(a, b / 2);
    if(b & 1) return (tmp * tmp % MOD) * (a % MOD) % MOD;
    else return (tmp * tmp % MOD);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        // 2 ^ (n - 1)
        cout << power(2, n - 1) << endl;
    }

    return 0;
}