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
    stack<int> st;
    for (int i = 0; s[i]; ++i) {
        if(isdigit(s[i])) st.push(s[i] - '0');
        else {
            int x1 = st.top(); st.pop();
            int x2 = st.top(); st.pop();

            int tmp;
            if(s[i] == '+') tmp = x2 + x1;
            else if(s[i] == '-') tmp = x2 - x1;
            else if(s[i] == '*') tmp = x2 * x1;
            else tmp = x2 / x1;

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