#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int n) {
    string s = to_string(n);

    int i = 0;
    while(i <= s.size() - 1 && s[i] <= '1') ++i;

    for (int j = i; j <= s.size() - 1; ++j) {
        s[j] = '1';
    }

    int res = 0;
    int k = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        res += (s[i] - '0') * k;
        k *= 2;
    }

    cout << res << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        solve(n);
    }   

    return 0;
}