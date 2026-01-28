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

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        for (int i = 1; i <= n; ++i){
            string tmp = q.front();
            q.pop();

            cout << tmp << " ";

            if(i == n) break;
            q.push(tmp + '0');
            q.push(tmp + '1');
        } 
        cout << endl;
    }   

    return 0;
}