#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        ll k; string a, b; 
        cin >> k >> a >> b;

        while(a.size() < b.size()) a = "0" + a;
        while(b.size() < a.size()) b = "0" + b;

        int len = a.size();

        string res = "";
        int carry = 0;

        // right to left
        for (int i = len - 1; i >= 0; --i) {
            int digitA = a[i] - '0';
            int digitB = b[i] - '0';

            int sum = digitA + digitB + carry;

            res += to_string(sum % k);
            carry = sum / k;
        }

        if(carry > 0) {
            res += to_string(carry);
        }

        reverse(res.begin(), res.end());

        cout << res << endl;
    }

    return 0;
}