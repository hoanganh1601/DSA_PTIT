#include <bits/stdc++.h>
// #define int long long
#define ll long long 
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

const int MOD = 1e9 + 7;

ll power(ll a, ll b) {
    if(a == 1 || b == 0) return 1;

    ll tmp = power(a, b / 2) % MOD;

    if(b & 1) return (tmp * tmp % MOD) * a % MOD;
    else return tmp * tmp % MOD;
}

signed main(){

    speed;  

    int test; 
    cin >> test;
    ll n;
    while(test--) {
        cin >> n;

        ll k = n;
        ll dao = 0;

        while(k) {
            dao = dao * 10 + k % 10;
            k /= 10;
        }

        cout << power(n, dao) << endl;
    }

    

    return 0;
}