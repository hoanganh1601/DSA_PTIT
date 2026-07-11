#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int a[n], freq[n];
    unordered_map<int, int> tmp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++tmp[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        freq[i] = tmp[a[i]];
    }

    vector<int> ans(n, -1);
    
    // Store idx
    stack<int> st;
    
    for (int i = 0; i < n; ++i) {
        if(st.empty()) st.push(i);
        else if(freq[st.top()] > freq[i]) st.push(i);
        else {
            while(!st.empty() && freq[st.top()] < freq[i]) {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    for (int x : ans) cout << x << " ";
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