#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void solve(int n) {
    queue<int> q;
    q.push(1);

    while(1) {
        int x = q.front();
        q.pop();

        if(x % n == 0) {
            cout << x << endl;
            return;
        }

        q.push(x * 10);
        q.push(x * 10 + 1);
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    
    int n; 
    while(test--) {
        cin >> n;
        solve(n);
    }

    return 0;
}