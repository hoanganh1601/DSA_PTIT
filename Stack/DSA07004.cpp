#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int solve(string s) {
    int open = 0, close = 0;

    stack<char> st;
    for (int i = 0; s[i]; ++i) {
        if(s[i] == '(') st.push(s[i]);
        else {
            if(!st.empty() && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
    }

    while(!st.empty()) {
        if(st.top() == '(') ++open;
        else ++close;
        
        st.pop();
    }

    return (open + 1) / 2 + (close + 1) / 2;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    
    string t;
    while(test--) {
        cin >> t;
        cout << solve(t) << endl;
    } 

    return 0;
}