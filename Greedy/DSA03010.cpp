#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int x;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            cin >> x;
            pq.push(x);
        }

        if(n == 1) {
            cout << pq.top() << endl;
            continue;
        }

        int ans = 0;

        while(pq.size() >= 2) {
            int x1 = pq.top(); pq.pop();
            int x2 = pq.top(); pq.pop();
            ans += (x1 + x2);
            pq.push(x1 + x2);
        }

        cout << ans << endl;
    }   

    return 0;
}