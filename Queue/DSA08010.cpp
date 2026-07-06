#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int solve(int n) {
    if(n == 1) return 0;

    queue<pair<int, int>> q;
    unordered_set<int> vs;

    q.push({n, 0});
    vs.insert(n);

    while(!q.empty()) {
        int val = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Operation (a): Subtract 1
        if(val - 1 == 1) return steps + 1;
        if(val - 1 > 1 && vs.find(val - 1) == vs.end()) {
            q.push({val - 1, steps + 1});
            vs.insert(val - 1);
        }

        // Operation (b): Max(u, v) where u * v = val
        // Check factors up to sqrt(val)
        for (int i = 2; i <= sqrt(val); ++i) {
            if(val % i == 0) {
                int maxFactor = val / i;
                if(maxFactor == 1) {
                    return steps + 1;
                }

                if(vs.find(maxFactor) == vs.end()) {
                    q.push({maxFactor, steps + 1});
                    vs.insert(maxFactor);
                }
            }
        }
    }

    return -1;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}