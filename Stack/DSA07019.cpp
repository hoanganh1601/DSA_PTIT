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

        stack<int> st1;
        vector<int> posPhai(n + 5, n + 1);
        for (int i = 1; i <= n; ++i) {
            if(st1.empty()) st1.push(i);
            else if(a[st1.top()] < a[i]) st1.push(i);
            else {
                while(!st1.empty() && a[st1.top()] > a[i]) {
                    posPhai[st1.top()] = i;
                    st1.pop();
                }
                st1.push(i);
            } 
        }


        stack<int> st2;
        vector<int> posTrai(n + 5, 0);
        for (int i = n; i >= 1; --i) {
            if(st2.empty()) st2.push(i);
            else if(a[st2.top()] < a[i]) st2.push(i);
            else {
                while(!st2.empty() && a[st2.top()] > a[i]) {
                    posTrai[st2.top()] = i;
                    st2.pop();
                }
                st2.push(i);
            } 
        }

        ll ans = -1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, 1ll * a[i] * (posPhai[i] - posTrai[i] - 1));
            // cout << posTrai[i] << " " << posPhai[i] << endl;
        }
        cout << ans << endl;
    }

    return 0;
}