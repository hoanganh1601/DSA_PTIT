#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

bool cmp(ii &a, ii &b) {
    // Value / weight

    double ratioA = (double)a.second / a.first;
    double ratioB = (double)b.second / b.first;

    return ratioA > ratioB;
}

void solve() {
    int n, w;
    cin >> n >> w;

    vector<ii> listRes;
    listRes.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        listRes.push_back({y, x});
    }

    sort(listRes.begin(), listRes.end(), cmp);

    double totalVal = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; ++i) {
        if(curWeight + listRes[i].first <= w) {
            curWeight += listRes[i].first;
            totalVal += listRes[i].second;
        }
        else {
            // Only take a fraction of the item
            int remainCapacity = w - curWeight;
            totalVal += listRes[i].second * ((double) remainCapacity / listRes[i].first);
            break; // completely full
        }
    }

    cout << fixed << setprecision(2) << totalVal << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}