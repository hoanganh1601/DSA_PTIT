#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

// Function to perform Left Clockwise Rotation
string rotateLeft(string s) {
    string res = s;
    res[0] = s[3];
    res[1] = s[0];
    res[4] = s[1];
    res[3] = s[4];
    return res;
}

// Function to perform Right Clockwise Rotation
string rotateRight(string s) {
    string res = s;
    res[1] = s[4];
    res[2] = s[1];
    res[5] = s[2];
    res[4] = s[5];
    return res;
}

void solve() {
    string start = "", target = "";

    for (int i = 0; i < 6; ++i) {
        int x; cin >> x;
        start += to_string(x);
    }

    for (int i = 0; i < 6; ++i) {
        int x; cin >> x;
        target += to_string(x);
    }

    if(start == target) {
        cout << 0 << endl;
        return;
    }

    queue<pair<string, int>> q;
    unordered_set<string> vs;

    q.push({start, 0});
    vs.insert(start); // visited

    while(!q.empty()) {
        string curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        string leftNode = rotateLeft(curr);
        if(leftNode == target) {
            cout << steps + 1 << endl;
            return;
        }
        if(vs.find(leftNode) == vs.end()) {
            q.push({leftNode, steps + 1});
            vs.insert(leftNode);
        }

        string rightNode = rotateRight(curr);
        if(rightNode == target) {
            cout << steps + 1 << endl;
            return;
        }

        if(vs.find(rightNode) == vs.end()) {
            q.push({rightNode, steps + 1});
            vs.insert(rightNode);
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