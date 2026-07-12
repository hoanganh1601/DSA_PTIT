#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MAX_VAL = 1000005;
int bit[MAX_VAL];

void update (int i) {
    for (; i < MAX_VAL; i += i & -i) bit[i]++;
}

int get(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    stack<int> st;
    
    ll ans = 0; 

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i > 0; i--) {
        if (a[i] % 2 == 0) {
            // Count previously inserted even numbers strictly less than a[i]
            ans += get(a[i] - 1);
            st.push(a[i]);
        } 
        else {
            // Encountered an odd number: flush the buffer (stack) into the BIT
            while (!st.empty()) {
                update(st.top());
                st.pop();
            }
        }
    }

    cout << ans << endl;
    return 0;
}
