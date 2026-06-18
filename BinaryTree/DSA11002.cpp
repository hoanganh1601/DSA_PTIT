#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int n;

// left : 2*i + 1
// right : 2*i + 2
ll calc(vector<string> &tree, int i) {

    if(i >= n) return 0;

    if(tree[i] == "+") return calc(tree, 2 * i + 1) + calc(tree, 2 * i + 2);
    else if(tree[i] == "*") return calc(tree, 2 * i + 1) * calc(tree, 2 * i + 2);
    else if(tree[i] == "-") return calc(tree, 2 * i + 1) - calc(tree, 2 * i + 2);
    else if(tree[i] == "/") return calc(tree, 2 * i + 1) / calc(tree, 2 * i + 2);
    else {
        return stoll(tree[i]);
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;
        vector<string> tree(n + 5);
    
        for (int i = 0; i < n; ++i) {
            cin >> tree[i];
        }

        cout << calc(tree, 0) << endl;
    }

    return 0;
}