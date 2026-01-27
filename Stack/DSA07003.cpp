#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

bool isCheck(char x) {
    if(x == '+' || x == '-' || x == '*' || x == '/') return true;
    return false;
}

bool solve(string s) {
    stack<char> st;

    for (int i = 0; s[i]; ++i) {
        if(s[i] == '(') st.push(s[i]);
        else if(isCheck(s[i])) st.push(s[i]);
        else if (s[i] == ')') {
            if(st.empty() || st.top() == '(') return true;

            while(!st.empty() && st.top() != '(') {
                st.pop();
            }

            // pop "("
            if(!st.empty()) st.pop();
        }

        // cout << st.top() << endl;
    }

    return false;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    cin.ignore();

    string s;
    while(test--) {

        getline(cin, s);
        if(solve(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }   

    return 0;
}