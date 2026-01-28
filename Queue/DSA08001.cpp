#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int q) {
    queue<int> pq;
    while(q--) {
        int operations;
        cin >> operations;

        if(operations == 1) cout << pq.size() << endl;
        else if(operations == 2) {
            if(pq.empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(operations == 3) {
            int x; cin >> x;
            pq.push(x);
        }
        else if(operations == 4) {
            if(!pq.empty()) pq.pop();
        }
        else if(operations == 5) {
            if(!pq.empty()) cout << pq.front() << endl;
            else cout << -1 << endl;
        }
        else if(operations == 6) {
            if(!pq.empty()) cout << pq.back() << endl;
            else cout << -1 << endl;
        }
    }
}

signed main(){

    speed;  
    
    int test; cin >> test;
    while(test--) {
        int q;
        cin >> q;
        solve(q);
    }

    return 0;
}