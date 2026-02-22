#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;
const int MAX = 1000005;

bool isPrime[MAX];
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAX; ++i) isPrime[i] = true;
    isPrime[0] = false; isPrime[1] = false;

    for (int i = 2; i < MAX; ++i) {
        if(isPrime[i]) primes.pb(i);

        for (int x : primes) {
            if(i * x > MAX) break;
            isPrime[i * x] = false;
            if(x % i == 0) break; 
        }
    }
}

void solve(int n) {
    if(n <= 3) cout << -1 << endl;
    else {
        bool ok = false;
        for (int i = 2; i <= n / 2; ++i) {
            if(isPrime[i] && isPrime[n - i]) {
                cout << i << " " << n - i << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
}

signed main(){

    speed;  

    int test, n;
    cin >> test;
    sieve();
    while(test--) {
        cin >> n;
        // for (int i = 1; i <= n; ++i) {
        //     solve(i);
        // }
        solve(n);    
    }   

    return 0;
}