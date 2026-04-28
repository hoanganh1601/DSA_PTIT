#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    int vertex, edge;
    while(test--) {
        cin >> vertex >> edge;
        vector<int> inDegree(vertex + 1, 0);
        vector<int> outDegree(vertex + 1, 0);

        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v; // u -> v

            ++inDegree[v];
            ++outDegree[u];
        }

        bool check = true;
        for (int i = 1; i <= vertex; ++i) {
            if(inDegree[i] != outDegree[i]) {
                check = false;
                break;
            }
        }

        cout << check << endl;
    }

    return 0;
}