#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

string res;

void convert() {
    cout << res[0];
    int x = (res[0] - '0');
    for (int i = 1; res[i]; ++i) {
        x = (res[i] - '0') ^ x;
        cout << x;
    }
    cout << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> res;
        // gray -> binary
        convert();
    }

    return 0;
}