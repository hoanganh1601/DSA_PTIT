#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    string a; cin >> a;
    stack<int> numRes;
    stack<string> stringRes;

    string cur = "";
    int curNum = 0;

    for (char c : a) {
        if(isdigit(c)) curNum = curNum * 10 + (c - '0');
        else if(c == '[') {
            // Handle cases where the bracket has no explicit multiplier
            if (curNum == 0) {
                curNum = 1; 
            }

            numRes.push(curNum);
            stringRes.push(cur);
            curNum = 0;
            cur = "";
        }
        else if(c == ']') {
            // decode
            int repeatTimes = numRes.top(); 
            numRes.pop();

            string prev = stringRes.top();
            stringRes.pop();

            string tmp = "";
            for (int i = 0; i < repeatTimes; ++i) {
                tmp += cur;
            }
            cur = prev + tmp;
        }
        else {
            // letter
            cur += c;
        }
    }

    cout << cur << endl;
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