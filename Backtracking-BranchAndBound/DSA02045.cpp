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
char c[17];
vector<char> listRes;

void Try(int start) {

    if(!listRes.empty()) {
        for (char x : listRes) cout << x;
        cout << " ";
    }

    for (int j = start; j <= n; ++j) {
        listRes.pb(c[j]);
        Try(j + 1);
        listRes.pob();
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> c[i];

        Try(1);
        cout << endl;
    }   

    return 0;
}