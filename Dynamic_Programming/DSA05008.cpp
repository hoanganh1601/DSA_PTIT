#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    int n, s;
    while(test--) {
        cin >> n >> s;
        int a[n + 1]; for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<bool> dp(s + 1, false); // dp[i]: Có thể tạo ra tổng thứ i hay không
        dp[0] = true; // luôn tạo ra được tổng = 0, phần tử rỗng
        
        for (int i = 1; i <= n; ++i) {

            // Duyệt từ s -> a[i] để không bị đánh dấu lại nhiều lần (mỗi phần tử chỉ sử dụng 1 lần)
            for (int j = s; j >= a[i]; --j) {
                if(dp[j - a[i]]) dp[j] = true;
            }
        }   

        if(dp[s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}