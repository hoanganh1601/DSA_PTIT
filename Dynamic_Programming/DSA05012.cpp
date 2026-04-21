#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

const int MOD = (int) 1e9 + 7;

int n, k;
ll C[1001][1001];

void init() {
    /*
    1
    1 1
    1   1

    */ 
    
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if(j == 0 || i == j || i == 1000) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;

    init();

    while(test--) {
        cin >> n >> k;
        cout << C[n][k] << endl;
    }

    return 0;
}