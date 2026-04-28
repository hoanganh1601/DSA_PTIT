#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    int vertex, edge;
    while(test--) {
        cin >> vertex >> edge;
        vector<int> degree(vertex + 1, 0);
    
        int cntOdd = 0;
        for (int i = 1; i <= edge; ++i) {
            int u, v;
            cin >> u >> v;
            ++degree[u]; ++degree[v]; 
        }

        for (int i = 1; i <= vertex; ++i) {
            if(degree[i] % 2 == 1) ++cntOdd;
        }

        if(cntOdd == 0) cout << 2 << endl; // Euler curcuit
        else if(cntOdd == 2) cout << 1 << endl; // Euler path
        else cout << 0 << endl;
    }

    return 0;
}