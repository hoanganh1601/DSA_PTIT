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

    stack<int> st;
    string operations;
    while(test--) {
        cin >> operations;
        if(operations == "PUSH") {
            int n; cin >> n;
            st.push(n);
        }

        else if(operations == "POP") {
            if(!st.empty()) st.pop();
        }

        else if(operations == "PRINT") {
            if(st.empty()) cout << "NONE" << endl;
            else cout << st.top() << endl;
        }
    }   

    return 0;
}