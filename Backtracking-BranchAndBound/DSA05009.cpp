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
int a[102];
int subSum;
bool check = false;

void Try(int i, int curSum) {

    if(check) return;

    if(curSum == subSum) {
        check = true;
        return;
    }

    if(i > n) return;

    // pick
    if(curSum + a[i] <= subSum) Try(i + 1, curSum + a[i]);
    
    //not pick
    Try(i + 1, curSum);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if(sum % 2 != 0) cout << "NO" << endl;
        else {
            subSum = sum / 2;
            Try(1, 0);

            if(check) cout << "YES" << endl;
            else cout << "NO" << endl;

            check = false;
        }
    }    

    return 0;
}