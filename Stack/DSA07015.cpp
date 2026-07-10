#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int priority(char op) {
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    return 0;
}

ll cal(ll a, ll b, char op) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else if(op == '/') return a / b;
    else if(op == '^') return 1ll * pow(a, b);
}

void solve() {
    string s; cin >> s;
    stack<ll> values;
    stack<char> ops;

    for (int i = 0; s[i]; ++i) {
        if(isdigit(s[i])) {
            ll val = 0;
            while(i < s.size() && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                ++i;
            }
            values.push(val);
            --i;

            // Decrement i because the outer for-loop will increment it again
        }
        
        else if(s[i] == '(') {
            ops.push(s[i]);
        }

        else if(s[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                ll val1 = values.top(); values.pop();
                ll val2 = values.top(); values.pop();

                char op = ops.top(); ops.pop();
                values.push(cal(val2, val1, op));
            }
            if(!ops.empty()) ops.pop(); // remove the '(' from the stack
        }

        else {
            while(!ops.empty() && priority(ops.top()) >= priority(s[i])) {
                ll val1 = values.top(); values.pop();
                ll val2 = values.top(); values.pop();

                char op = ops.top(); ops.pop();
                values.push(cal(val2, val1, op));
            }
            ops.push(s[i]);
        }
    }

    while(!ops.empty()) {
        ll val1 = values.top(); values.pop();
        ll val2 = values.top(); values.pop();

        char op = ops.top(); ops.pop();
        values.push(cal(val2, val1, op));
    }

    cout << values.top() << endl;
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