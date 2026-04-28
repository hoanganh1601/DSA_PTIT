#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int vertex;
    cin >> vertex;
    cin.ignore();

    vector<vector<bool>> res(vertex + 1, vector<bool>(vertex + 1, 0));
    for (int i = 1; i <= vertex; ++i) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        int so;
        while(ss >> so) {
            res[i][so] = true;
        }
    }

    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}