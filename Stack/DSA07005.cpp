#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    
    stack<int> st;
    // status: 0 - not flip
    //         1 - flip
    // 0 means no sign flipping
    st.push(0);

    string res = "";    
    for (int i = 0; s[i]; ++i) {
        if(s[i] == '(') {
            // flip
            if(i > 0 && s[i - 1] == '-') {
                st.push(st.top() ^ 1); // Using XOR;
            }
            else st.push(st.top()); // '+' : not flip
        }
        else if(s[i] == ')') st.pop();
        else if(s[i] == '+' || s[i] == '-') {
            if(st.top() == 1) {
                if(s[i] == '+') res += '-';
                else res += '+';
            }
            else res += s[i];
        }
        // operands (letters and variables)
        else res += s[i];
    }

    cout << res << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}