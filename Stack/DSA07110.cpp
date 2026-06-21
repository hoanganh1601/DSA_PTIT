#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

bool solve(string& s) {
    stack<char> st;
    // xau rong la mot day ngoac dung
    for (char c : s) {
        if(st.empty()) st.push(c);
        else {
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if(c == ')') {
                    if(st.top() == '(') st.pop();
                    else return false;
                }

                else if(c == ']') {
                    if(st.top() == '[') st.pop();
                    else return false;
                }

                else if(c == '}') {
                    if(st.top() == '{') st.pop();
                    else return false;
                }
            }
        }
    }

    return true;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string s; cin >> s;
        if(solve(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}