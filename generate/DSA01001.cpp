#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void generate(string &s) {
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1') {
        s[i] = '0';
        --i;
    }

    if(i == -1) return;
    else s[i] = '1';
}

signed main(){

    speed;  

    int test; cin >> test;
    string s;
    while(test--) {
        cin >> s;
        generate(s);
        cout << s << endl;        
    }

    return 0;
}