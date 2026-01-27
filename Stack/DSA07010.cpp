#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; --i) {
        if(isalpha(s[i])) st.push(string(1, s[i]));
        else {
            string x1 = st.top(); st.pop();
            string x2 = st.top(); st.pop();

            string tmp = x1 + x2 + s[i];
            st.push(tmp);
        }
    }

    cout << st.top() << endl;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    string s;
    while(test--) {
        cin >> s;
        solve(s);
    }

    return 0;
}