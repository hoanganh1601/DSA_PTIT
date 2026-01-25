#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int fibo[93];

void init() {
    fibo[0] = 0; fibo[1] = 1;
    for (int i = 2; i <= 92; ++i) fibo[i] = fibo[i - 1] + fibo[i - 2];
}

char find(int n, int i) {
    if(n == 1) return 'A';
    else if(n == 2) return 'B';

    if(i <= fibo[n - 2]) return find(n - 2, i);
    else return find(n - 1, i - fibo[n - 2]);
}

signed main(){

    speed;  

    init();
    int test; cin >> test;
    int n, i;
    while(test--) {
        cin >> n >> i;
        cout << find(n, i) << endl;
    }

    return 0;
}