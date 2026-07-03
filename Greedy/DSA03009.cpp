#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Work {
    int code, dl, profit;
};

int cmp(Work &x, Work &y) {
    if(x.profit != y.profit) return x.profit > y.profit;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        vector<Work> listRes;
        int maxVal = -1;
        listRes.reserve(n);
        for (int i = 0; i < n; ++i) {
            int x, y, z; cin >> x >> y >> z;
            listRes.push_back({x, y, z});

            maxVal = max(maxVal, y);
        }

        sort(listRes.begin(), listRes.end(), cmp);
        vector<bool> slots(maxVal + 1);

        int cntJob = 0, totalProfit = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = listRes[i].dl; j > 0; --j) {
                if(!slots[j]) {
                    slots[j] = true;
                    ++cntJob;
                    totalProfit += listRes[i].profit;

                    break;
                }
            }
        }

        cout << cntJob << " " << totalProfit << endl;
    }

    return 0;
}