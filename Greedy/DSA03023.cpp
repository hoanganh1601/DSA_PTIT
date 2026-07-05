#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    char arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x = 0, t = 0, d = 0;
    for (char c : arr) {
        if(c == 'X') ++x;
        else if(c == 'T') ++t;
        else ++d;
    }

    int cnt = 0;
    int x_in_d = 0, d_in_x = 0;

    // zone D
    for (int i = x + t; i < n; ++i) {
        if(arr[i] != 'D') ++cnt;
        if(arr[i] == 'X') ++x_in_d;
    }

    // zone x
    for (int i = 0; i < x; ++i) {
        if(arr[i] != 'X') ++cnt;
        if(arr[i] == 'D') ++d_in_x;
    }

    cout << cnt - min(x_in_d, d_in_x);

    return 0;
}