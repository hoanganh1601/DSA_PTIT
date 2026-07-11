#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> left(n, -1); // idx

    // Next Greater Element to the Left.
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        if(st.empty()) st.push(i);
        else if(a[st.top()] >= a[i]) st.push(i);
        else {
            while(!st.empty() && a[st.top()] < a[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if(left[i] == -1) cout << i + 1 << " ";
        else cout << i - left[i] << " ";
        // cout << left[i] << " ";
    }
    cout << endl;
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