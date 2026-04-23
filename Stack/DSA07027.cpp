#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cout.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        int n; cin >> n;
        int a[n + 1]; for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> ans(n + 1, -1);

        stack<int> st;  
        for (int i = 1; i <= n; ++i) {
            if(st.empty()) st.push(i);
            else if(a[st.top()] > a[i]) st.push(i);
            else {
                while(!st.empty() && a[st.top()] < a[i]) {
                    ans[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}