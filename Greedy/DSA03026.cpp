#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

void minValue(int n, int sum) {
    vector<int> arr(n, 0);
    --sum;

    for (int i = n - 1; i >= 1; --i) {
        if(sum >= 9) {
            arr[i] = 9;
            sum -= 9;
        }
        else {
            arr[i] = sum;
            sum = 0;
        }
    }

    arr[0] = sum + 1;

    for (int i = 0; i < n; ++i) cout << arr[i];
    cout << " ";
}

void maxValue(int n, int sum) {
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        if(sum >= 9) {
            arr[i] = 9;
            sum -= 9;
        }
        else {
            arr[i] = sum;
            sum = 0;
        }
    }

    for (int i = 0; i < n; ++i) cout << arr[i];
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, sum; cin >> n >> sum;

    if(sum > n * 9 || (sum == 0 && n != 1)) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    minValue(n, sum);
    maxValue(n, sum);

    return 0;
}