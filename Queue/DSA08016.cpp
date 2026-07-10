#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const string TARGET = "1238004765";

// Forward Left
string rotLeft(string s) {
    string res = s;
    res[0] = s[3]; res[1] = s[0]; res[5] = s[1];
    res[8] = s[5]; res[7] = s[8]; res[3] = s[7];
    return res;
}

// Forward Right
string rotRight(string s) {
    string res = s;
    res[1] = s[4]; res[2] = s[1]; res[6] = s[2];
    res[9] = s[6]; res[8] = s[9]; res[4] = s[8];
    return res;
}

// Reverse Left
string revLeft(string s) {
    string res = s;
    res[3] = s[0]; res[0] = s[1]; res[1] = s[5];
    res[5] = s[8]; res[8] = s[7]; res[7] = s[3];
    return res;
}

// Reverse Right
string revRight(string s) {
    string res = s;
    res[4] = s[1]; res[1] = s[2]; res[2] = s[6];
    res[6] = s[9]; res[9] = s[8]; res[8] = s[4];
    return res;
}

void solve() {
    string start = "";
    for (int i = 0; i < 10; ++i) {
        char c; 
        cin >> c; 
        start += c;
    }

    if (start == TARGET) {
        cout << 0 << endl;
        return;
    }

    unordered_map<string, int> fwd, bwd;
    queue<string> qFwd, qBwd;

    qFwd.push(start); fwd[start] = 0;
    qBwd.push(TARGET); bwd[TARGET] = 0;

    int ans = 1e9;

    while (!qFwd.empty() && !qBwd.empty()) {
        
        int szFwd = qFwd.size();
        while (szFwd--) {
            string curr = qFwd.front(); qFwd.pop();
            int d = fwd[curr];
            
            string nextL = rotLeft(curr);
            if (bwd.count(nextL)) ans = min(ans, d + 1 + bwd[nextL]);
            if (!fwd.count(nextL)) {
                fwd[nextL] = d + 1;
                qFwd.push(nextL);
            }

            string nextR = rotRight(curr);
            if (bwd.count(nextR)) ans = min(ans, d + 1 + bwd[nextR]);
            if (!fwd.count(nextR)) {
                fwd[nextR] = d + 1;
                qFwd.push(nextR);
            }
        }
        
        if (ans != 1e9) {
            cout << ans << endl;
            return;
        }

        int szBwd = qBwd.size();
        while (szBwd--) {
            string curr = qBwd.front(); qBwd.pop();
            int d = bwd[curr];

            string nextL = revLeft(curr);
            if (fwd.count(nextL)) ans = min(ans, d + 1 + fwd[nextL]);
            if (!bwd.count(nextL)) {
                bwd[nextL] = d + 1;
                qBwd.push(nextL);
            }

            string nextR = revRight(curr);
            if (fwd.count(nextR)) ans = min(ans, d + 1 + fwd[nextR]);
            if (!bwd.count(nextR)) {
                bwd[nextR] = d + 1;
                qBwd.push(nextR);
            }
        }
        
        if (ans != 1e9) {
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int test; 
    cin >> test;
    while (test--) {
        solve();
    }
    
    return 0;
}