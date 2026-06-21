#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        int a[n + 5]; for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<int> ans(n + 5, -1); // chỉ số của phần tử tiếp theo lớn hơn
        stack<int> st1;

        for (int i = 1; i <= n; ++i) {
            if(st1.empty()) st1.push(i);
            else if(a[st1.top()] > a[i]) st1.push(i);
            else {
                while(!st1.empty() && a[st1.top()] < a[i]) {
                    ans[st1.top()] = i;
                    st1.pop();
                }
                st1.push(i);
            }    
        }

        // for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        // cout << endl;

        vector<int> total(n + 5, -1); // lưu phần tử nhỏ hơn tiếp theo
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            if(st.empty()) st.push(i);
            else if(a[st.top()] < a[i]) st.push(i);
            else {
                while(!st.empty() && a[st.top()] > a[i]) {
                    total[st.top()] = a[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        // duyet
        for (int i = 1; i <= n; ++i) {
            if(ans[i] != -1) {
                cout << total[ans[i]] << " ";
            }
            else cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}