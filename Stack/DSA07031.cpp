#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

ll calc(ll x, ll y, string tmp) {
    if(tmp == "+") return x + y;
    else if(tmp == "-") return x - y;
    else if(tmp == "/") return x / y;
    else if(tmp == "*") return x * y;

    return 0;
}

ll num(string &x) {
    if(x[0] == '-') {
        ll res = 0, d = 1;
        for (int i = x.size() - 1; i >= 1; --i) {
            res = res + (x[i] - '0') * d;
            d *= 10;
        }
        return -res;
    }

    else {
        ll res = 0, d = 1;
        for (int i = x.size() - 1; i >= 0; --i) {
            res = res + (x[i] - '0') * d;
            d *= 10;
        }
        return res;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        string a[1005];
        for (int i = 1; i <= n; ++i) cin >> a[i];

        stack<ll> st;
        for (int i = n; i >= 1; --i) {
            if(a[i] == "+" || a[i] == "-" || a[i] == "/" || a[i] == "*") {
                ll x = st.top(); st.pop();
                ll y = st.top(); st.pop();

                st.push(calc(x, y, a[i])); 
            }
            else st.push(num(a[i]));
        }

        cout << st.top() << endl;
    }

    return 0;
}