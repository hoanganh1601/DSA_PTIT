#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    // Clean up the '+' signs
    for (int i = 0; i < a.length(); ++i) {
        if(a[i] == '+') a[i] = ' ';
    }
    for (int i = 0; i < b.length(); ++i) {
        if(b[i] == '+') b[i] = ' ';
    }

    stringstream sA(a), sB(b);
    string tok; 
    vector<pair<int, int>> m, n;

    // Parse polynomial A
    while(sA >> tok) {
        int i = tok.find("*x^");
        m.push_back({stoi(tok.substr(0, i)), stoi(tok.substr(i + 3))});
    }

    // Parse polynomial B
    while(sB >> tok) {
        int i = tok.find("*x^");
        n.push_back({stoi(tok.substr(0, i)), stoi(tok.substr(i + 3))});
    }

    vector<pair<int, int>> res;
    int i = 0, j = 0;

    while(i < m.size() && j < n.size()) {
        if(m[i].second > n[j].second) {
            res.push_back(m[i]);
            i++;
        } 
        else if (n[j].second > m[i].second) {
            res.push_back(n[j]);
            j++;
        } 
        else {
            
            int sum = m[i].first + n[j].first;
            if (sum != 0) { 
                res.push_back({sum, m[i].second});
            }
            i++; 
            j++;
        }
    }

    while(i < m.size()) {
        res.push_back(m[i]);
        i++;
    }

    while(j < n.size()) {
        res.push_back(n[j]);
        j++;
    }

    for (int k = 0; k < res.size(); ++k) {
        cout << res[k].first << "*x^" << res[k].second;
        if (k < res.size() - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; 
    if (cin >> test) {
        cin.ignore();
        while(test--) {
            solve();
        }
    }
    return 0;
}