#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        string s; cin >> s;
        stack<string> st;

        for (char x : s) {
            if(isalpha(x)) st.push(string(1, x));
            else {
                string s1 = st.top(); st.pop();
                string s2 = st.top(); st.pop();

                string res = x + s2 + s1;
                st.push(res);
            }
        }

        cout << st.top() << endl;
    }

    return 0;
}