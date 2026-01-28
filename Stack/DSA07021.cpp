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
    // avoid case : ()
    st.push(-1);
    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if(s[i] == '(') st.push(i);
        else {
            // pop )
            if(!st.empty()) st.pop();

            if(!st.empty()) ans = max(ans, i - st.top());
            else st.push(i);
        }
    }

    cout << ans << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    string s;
    while(test--) {
        cin >> s;
        solve(s);   
    }   

    return 0;
}