#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

vector<int> coinList = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;

    while(test--){
        cin >> n;
        int res = 0;
        for (int x : coinList) {
            res += n / x;
            n %= x;

            if(n <= 0) break;
        }

        cout << res << endl;
    }   

    return 0;
}