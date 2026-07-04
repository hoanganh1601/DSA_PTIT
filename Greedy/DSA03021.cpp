#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int arr[n]; 
    int minTotal = 0;
    int minValue = 2001;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        minTotal += arr[i];  // a[i] / b[i] = 0; 

        minValue = min(minValue, arr[i]);
    }

    minTotal += n; // a[i] / b[i] = 0;

    
    for (int i = minValue; i >= 1; --i) {
        int res = 0;
        bool ok = true;
        for (int tmp : arr) {


            int k = i + 1;
            int sum = tmp + 1;

            // sum / k = i --> sum = k * carry + r
            // r <= k - 1 -> sum <= k * carry + k - 1 -> carry >= (sum + 1) / (k + 1)
            
            int carry = (sum + k - 1) / k; // ceil
            res += carry;

            if(carry * i > tmp) {
                ok = false;
                break;
            }
        }

        if(ok) {
            minTotal = min(minTotal, res);
            break;
        }
    }

    cout << minTotal;

    return 0;
}