#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {


    int vertex;
    cin >> vertex;
    cin.ignore();

    vector<vector<int>> adj(vertex + 1);
    for (int i = 1; i <= vertex; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int neighbour;
        while(ss >> neighbour) {
            adj[i].push_back(neighbour);
        }
    }

    for (int i = 1; i <= vertex; ++i) {
        sort(adj[i].begin(), adj[i].end());
        for (int x : adj[i]) {
            if(x > i) cout << i << " " << x << endl;
        }
    }


    return 0;
}