#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

bool isValid(string &s) {
    if(s.size() <= 1) return false;

    int balance = 0;
    for (char c : s) {
        if(c == '(') ++balance;
        else if(c == ')') {
            --balance;
            if(balance < 0) return false;
        }
    }

    return balance == 0;
}

void solve() {
    string s; cin >> s;
    vector<string> res;
    res.reserve(s.size());
    queue<string> q;
    unordered_set<string> vs;

    q.push(s);
    vs.insert(s);

    bool found = false;

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string cur = q.front(); q.pop();
            if(isValid(cur)) {
                res.push_back(cur);
                found = true;
            }

            if(found) continue;

            for (int j = 0; j < cur.size(); ++j) {
                if(cur[j] != '(' && cur[j] != ')') continue;

                string nextStr = cur.substr(0, j) + cur.substr(j + 1);
                if(vs.find(nextStr) == vs.end()) {
                    q.push(nextStr);
                    vs.insert(nextStr);
                }
            }
        }
        if(found) break;
    }

    if(res.empty()) {
        cout << -1 << endl;
    }
    else {
        sort(res.begin(), res.end());
        for (string tmp : res) {
            cout << tmp << " ";
        }
        cout << endl;
    }
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