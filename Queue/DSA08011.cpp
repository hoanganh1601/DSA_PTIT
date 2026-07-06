#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long; 

int solve() {
    int n; 
    string startStr, endStr;
    cin >> n >> startStr >> endStr;

    unordered_set<string> dict;
    for (int i = 0; i < n; ++i) {
        string s; 
        cin >> s;
        dict.insert(s);
    }

    queue<pair<string, int>> q;
    q.push({startStr, 1});

    // Remove the starting word so do not revisit it
    if(dict.find(startStr) != dict.end()) dict.erase(startStr);

    while(!q.empty()) {
        string cur = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(cur == endStr) return steps;

        for (int i = 0; cur[i]; ++i) {
            char org = cur[i];
            for (char c = 'A'; c <= 'Z'; ++c) {
                if(c == org) continue; // Skip if it's the same character

                cur[i] = c;
                if(dict.find(cur) != dict.end()) {
                    q.push({cur, steps + 1});
                    dict.erase(cur);
                }
            }
            // restore the original character before moving to the next index
            cur[i] = org;
        }
    }

    return -1;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cout << solve() << endl;
    }

    return 0;
}