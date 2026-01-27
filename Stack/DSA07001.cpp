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

    string operations;
    stack<int> st;

    while(cin >> operations) {
        if(operations == "push") {
            int n; cin >> n;
            st.push(n);
        }

        else if(operations == "pop") {
            if(!st.empty()) st.pop();
        }

        else if(operations == "show"){
            if(st.empty()) cout << "empty" << endl;
            else {
                stack<int> tmp = st;
                vector<int> listRes;

                while(!tmp.empty()) {
                    listRes.pb(tmp.top());
                    tmp.pop();
                }  

                for (int i = listRes.size() - 1; i >= 0; --i) cout << listRes[i] << " ";
                cout << endl;
            }
        }
    }   

    return 0;
}