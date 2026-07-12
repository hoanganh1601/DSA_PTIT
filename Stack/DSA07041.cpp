#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        string s; cin >> s;
        int openBrackets = 0;

        int maxLen = 0;
        for (char c : s) {
            if(c == '(') ++openBrackets;
            else {
                if(openBrackets > 0) {
                    maxLen += 2; 
                    --openBrackets;
                }
            }
        }

        cout << maxLen << endl;
    }

    return 0;
}