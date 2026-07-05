#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long; 

void solve() {
    int s, t; 
    cin >> s >> t;

    // subtract 1 to reach it
    if(s >= t) {
        cout << s - t << endl;
        return;
    }

    queue<pair<int, int>> q;
    unordered_set<int> vs;

    q.push({s, 0}); 
    vs.insert(s);

    while(!q.empty()) {
        int cur = q.front().first; 
        int steps = q.front().second;
        q.pop();

        if(cur == t) {
            cout << steps << endl;
            return;
        }

        if(cur - 1 > 0 && vs.find(cur - 1) == vs.end()) {
            q.push({cur - 1, steps + 1});
            vs.insert(cur - 1);
        }

        if(cur * 2 <= 20000 && vs.find(cur * 2) == vs.end()) {
            q.push({cur * 2, steps + 1});
            vs.insert(cur * 2);
        }
    }

    cout << -1 << endl;
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