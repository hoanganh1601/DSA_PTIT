#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string s; cin >> s;
        vector<int> res;
        res.reserve(s.size() + 10);

        stack<int> st;

        for (int i = 0; i <= s.size(); ++i) {
            st.push(i + 1);

            if(i == s.size() || s[i] == 'I') {
                while(!st.empty()) {
                    res.push_back(st.top());
                    st.pop();
                }
            }
        }

        for (int x : res) cout << x;
        cout << endl;
    }

    return 0;
}