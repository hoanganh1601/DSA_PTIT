#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;
using ii = pair<int, int>;

bool canExtend(map<int, int>& mp, int x, int y) {
    auto it = mp.lower_bound(x);
    if (it == mp.begin()) return false;
    --it;
    return it->second < y;
}

void insertAndMaintain(map<int, int>& mp, int x, int y) {
    
    auto it = mp.upper_bound(x);
    
    if (it != mp.begin()) {
        auto prev_it = it;
        --prev_it;
        if (prev_it->second <= y) {
            return; 
        }
    }
    
    mp[x] = y;
    
    it = mp.upper_bound(x);
    while (it != mp.end() && it->second >= y) {
        it = mp.erase(it);
    }
}

int main() {
    
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    
    vector<ii> listRes;
    listRes.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        listRes.push_back({x, y});
    }
    
    vector<map<int, int>> dp;
    dp.push_back({}); 
    int maxVal = 0;
    
    for (int i = 0; i < n; ++i) {
        int x = listRes[i].first;
        int y = listRes[i].second;
        
        int low = 1, high = maxVal;
        int best_len = 0;
        
        while (low <= high) {
            int mid = (high + low) / 2;
            if (canExtend(dp[mid], x, y)) {
                best_len = mid;
                low = mid + 1; 
            } 
            else {
                high = mid - 1;
            }
        }
        
        int new_len = best_len + 1;
        
        if (new_len > maxVal) {
            maxVal = new_len;
            dp.push_back({});
        }
        
        insertAndMaintain(dp[new_len], x, y);
    }
    
    cout << maxVal << endl;

    return 0;
}