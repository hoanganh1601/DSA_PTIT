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
    
    queue<int> q;
    while(test--) {
        string s; cin >> s;
        if(s == "PUSH") {
            int x; cin >> x;
            q.push(x);
        }
        else if(s == "POP") {
            if(!q.empty()) q.pop();
        }
        else if(s == "PRINTFRONT"){
            if(!q.empty()) cout << q.front() << endl;
            else cout << "NONE" << endl;
        }
    }   

    return 0;
}