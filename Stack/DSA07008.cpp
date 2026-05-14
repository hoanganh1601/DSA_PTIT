#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int uuTien(char x) {
    if(x == '^') return 3;
    else if(x == '*' || x == '/') return 2;
    else if(x == '+' || x == '-') return 1;
    return 0;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        string s; cin >> s;
        stack<char> st;

        string res = "";

        for (char x : s) {
            if(isalpha(x)) res += x;
            else if(x == '(') st.push(x);
            else if(x == ')') {
                while(!st.empty() && st.top() != '(') {
                    char x = st.top(); st.pop();
                    res += x;
                }
                st.pop(); // pop (
            }
            else {
                while(!st.empty() && uuTien(st.top()) >= uuTien(x)) {
                    res += st.top(); 
                    st.pop();
                }
                st.push(x);
            }
        }

        // pop het phan con lai trong st
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        cout << res << endl;
    }

    return 0;
}