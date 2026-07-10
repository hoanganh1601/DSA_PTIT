#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int a[n]; 
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totalSum += a[i];
    }

    // Create three queues for the remainders
    queue<int> q0, q1, q2;

    //  Sort ascending so the smallest numbers go into the queues first
    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        if(a[i] % 3 == 0) q0.push(a[i]);
        else if(a[i] % 3 == 1) q1.push(a[i]);
        else q2.push(a[i]); 
    }

    if(totalSum % 3 == 1) {
        if(!q1.empty()) q1.pop();
        else if(q2.size() >= 2) {
            q2.pop(); q2.pop();
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    else if(totalSum % 3 == 2) {
        if(!q2.empty()) q2.pop();
        else if(q1.size() >= 2) {
            q1.pop(); q1.pop();
        }
        else {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> ans;
    ans.reserve(n + 5);
    while(!q0.empty()) {
        ans.push_back(q0.front()); q0.pop();
    }
    while(!q1.empty()) {
        ans.push_back(q1.front()); q1.pop();
    }
    while(!q2.empty()) {
        ans.push_back(q2.front()); q2.pop();
    }

    if(ans.size() == 0) {
        cout << -1 << endl;
        return;
    }

    sort(ans.begin(), ans.end(), greater<int>());
    // Handle the all-zeros edge case (IMPORTANT)
    if (ans[0] == 0) {
        cout << 0 << endl;
        return;
    }

    for(int x : ans) cout << x;
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