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
    cin.ignore();

    string s;
    while(test--) {
        getline(cin, s);
        stringstream ss(s);
        stack<string> st;
        while(ss >> s) {
            st.push(s);
        }

        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

    return 0;
}