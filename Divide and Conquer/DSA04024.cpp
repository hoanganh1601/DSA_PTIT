#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix{
    int mat[11][11];
};

int multiply() {

}

int power(int a[11][11], int n, int k) {
    // init ma tran don vi
    int res[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) res[i][j] = 1;
    }

    while(k) {
        if(k % 2 == 1) res = multiply(res, a);
        
        k /= 2;
    }
}

signed main(){

    speed;  

    int test; cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        int matrix[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> matrix[i][j];
        }
        cout << power(matrix, n, k) << endl;
    }   

    return 0;
}