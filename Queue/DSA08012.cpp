#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int MaxR = 100005;
vector<int> dp(MaxR, 0);

bool isValid(int n) {
    vector<bool> seen(10, false);

    if(n == 0) return true;

    while(n > 0) {
        int digit = n % 10;

        if(digit > 5) return false;
        if(seen[digit]) return false;

        seen[digit] = true;
        n /= 10;
    }

    return true;
}

void precompute() {
    // base case: 0 is valid
    dp[0] = 1;

    for (int i = 1; i < MaxR; ++i) {
        dp[i] = dp[i - 1] + isValid(i);
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precompute();
    
    int test; cin >> test;
    while(test--) {
        int left, right;
        cin >> left >> right;
        cout << dp[right] - dp[left - 1] << endl;
    }

    return 0;
}