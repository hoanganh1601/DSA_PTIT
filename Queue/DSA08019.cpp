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
    vector<string> res;
    queue<string> q;
    q.push("6"); q.push("8");

    while(!q.empty()) {
        string top = q.front();
        q.pop();

        res.push_back(top);
        if(top.size() < n) {
            q.push(top + "6");
            q.push(top + "8");
        }
    }

    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

signed main(){

    speed;  

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        
        solve(n);
    }   

    return 0;
}