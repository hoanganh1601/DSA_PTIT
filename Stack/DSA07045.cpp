#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    vector<char> leftStack, rightStack;

    for (char c : s) {
        if(c == '<') {
            if(!leftStack.empty()) {
                rightStack.push_back(leftStack.back());
                leftStack.pop_back();
            }
        }
        else if(c == '>') {
            if(!rightStack.empty()) {
                leftStack.push_back(rightStack.back());
                rightStack.pop_back();
            } 
        }
        else if(c == '-') {
            if(!leftStack.empty()) leftStack.pop_back();
        }
        else leftStack.push_back(c);
    }

    for (char c : leftStack) cout << c;
    for (int i = rightStack.size() - 1; i >= 0; --i) {
        cout << rightStack[i];
    }

    return 0;
}