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
int cnt = 0;    
int a[22];

void display() {
    cout << cnt << ": ";
    for (int i = 1; i <= k; ++i) cout << a[i] << " ";
    cout << endl;
}

bool checkPrime(int n) {
    if(n < 2) return false;
    else if(n == 2 || n == 3) return true;
    else if(n % 2 == 0 || n % 3 == 0) return false;
    else {
        for (int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
    }
    return true;
}

void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) {
        a[i] = j;
        if(i == k) {
            ++cnt;
            if(checkPrime(cnt)) display();
        }
        else Try(i + 1);
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    Try(1);

    return 0;
}