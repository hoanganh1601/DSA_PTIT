#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int n, k;
vector<int> arr;
int ans;
int targetSum;

void Try(int pos, int groups) {
    if(groups == k && pos == n) {
        ++ans;
        return;
    }

    if(groups == k || pos == n) return;

    int curSum = 0;
    for (int i = pos; i < n; ++i) {
        curSum += arr[i];
        if(curSum == targetSum) {
            Try(i + 1, groups + 1);
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    arr.resize(n);

    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    if(totalSum % k != 0) {
        cout << 0 << endl;
        return 0;
    }

    targetSum = totalSum / k;
    ans = 0;

    Try(0, 0);
    cout << ans;

    return 0;
}