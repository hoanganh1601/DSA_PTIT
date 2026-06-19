#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left, *right;
    node (int u) {
        data = u;
        left = NULL;
        right = NULL;
    }
};

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;
            s.insert(u); 
            s.insert(v);
        }

        for (int x : s) cout << x << " ";
        cout << endl;
    }

    return 0;
}