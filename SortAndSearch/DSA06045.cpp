#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    string arr; cin >> arr;

    vector<ll> blocks;
    ll curLen = 1;

    for (int i = 1; i < n; ++i) {
        if(arr[i] == arr[i - 1]) ++curLen;
        else {
            blocks.push_back(curLen);
            curLen = 1;
        }
    }
    blocks.push_back(curLen);

    ll totalSub = n * (n + 1) / 2;
    ll badSub = n; // All substrings of length 1 are bad
    for (int i = 0; i < blocks.size() - 1; ++i) {
        badSub += (blocks[i] + blocks[i + 1] - 1);
    }

    ll goodSub = totalSub - badSub;
    cout << goodSub;


    return 0;
}