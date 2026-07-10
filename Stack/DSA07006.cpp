#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void removeParentheses(string &curr, queue<string>& q, set<string>& vs) {
    vector<pair<int, int>> pairs;
    stack<int> st;

    // Find all matching pairs in the curr string
    for (int i = 0; curr[i]; ++i) {
        if(curr[i] == '(') st.push(i);
        if(curr[i] == ')') {
            pairs.push_back({st.top(), i});
            st.pop();
        }
    }

    for (auto p : pairs) {
        string nextStr = curr;
        nextStr.erase(p.first, 1);
        nextStr.erase(p.second - 1, 1); // Shift index left by 1
    
        // If this is a new string, push it to the queue and mark it as visited
        if(vs.count(nextStr) == 0) {
            q.push(nextStr);
            vs.insert(nextStr);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    set<string> vs;
    queue<string> q;
    
    q.push(s);

    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        removeParentheses(curr, q, vs);
    }

    for (string res : vs) cout << res << endl;

    return 0;
}