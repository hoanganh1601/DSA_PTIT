#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

const int MOD = 1000000007;

int power(int a, int b) {
    if(a == 1 || b == 0) return 1;

    int tmp = power(a, b / 2);
    tmp = (tmp % MOD) * (tmp % MOD) % MOD;

    if(b % 2 == 0) return tmp;
    else return (a % MOD) * (tmp % MOD) % MOD;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        cout << power(n, k) << endl;
    }   

    return 0;
}