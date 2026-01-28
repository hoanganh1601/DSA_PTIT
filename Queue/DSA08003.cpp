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

    deque<int> dq;
    int q; cin >> q;
    
    string s;
    while(q--) {
        cin >> s;
        if(s == "PUSHBACK") {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(s == "PRINTBACK") {
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "PUSHFRONT") {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if(s == "PRINTFRONT") {
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPFRONT") {
            if(!dq.empty()) dq.pop_front();
        }
        else if(s == "POPBACK") {
            if(!dq.empty()) dq.pop_back();
        }
    }

    return 0;
}