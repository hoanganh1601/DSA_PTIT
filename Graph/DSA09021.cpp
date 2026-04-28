#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int vertex; cin >> vertex;
    vector<int> adj[vertex + 1];

    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            int val;
            cin >> val;
            if(val == 1) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= vertex; ++i) {
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}