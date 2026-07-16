#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

string add(string a, string b) {
    string res = "";
    int carry = 0;

    int i = a.size() - 1, j = b.size() - 1;

    while(i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';

        res += to_string(sum % 10);
        carry = sum / 10;
    }   

    reverse(res.begin(), res.end());
    return res;
}

string mul(string a, string b) {
    if(a == "0" || b == "0") return "0";

    int sizeA = a.size(), sizeB = b.size();
    vector<int> res(sizeA + sizeB, 0);

    // Multiply each digit and add to the corresponding position
    for (int i = sizeA - 1; i >= 0; --i) {
        for (int j = sizeB - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + (res[i + j + 1]);

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string ans = "";
    for (int num : res) {
        if((ans.empty() && num == 0) == 0) {
            ans += to_string(num);
        }
    }

    if(ans.empty()) return "0";
    else return ans;
}

string catalan[105];
void precompute() {
    catalan[0] = "1";
    catalan[1] = "1";

    for (int i = 2; i <= 100; ++i) {
        catalan[i] = "0";
        for (int j = 0; j < i; ++j) {
            // C[i] += C[j] * C[i - j - 1]
            string tmp = mul(catalan[j], catalan[i - j - 1]);
            catalan[i] = add(catalan[i], tmp);
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << catalan[n] << endl;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    precompute();

    int test; cin >> test;
    while(test--) {
        solve();
    }


    return 0;
}
