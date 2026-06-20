#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

bool check(string s, int left, int right) {
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        ++left; --right;
    }

    return true;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    s = "0" + s;

    int q; cin >> q;
    while(q--) {
        char c; int u, x;
        cin >> c >> u >> x;
        if(c == 'c') s[u] = x + '0';
        if(c == 'q') {
            int left = u, right = x;
            if(check(s, left, right)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        
    }

    return 0;
}