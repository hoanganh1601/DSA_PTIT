#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; 
    cin >> test;

    while(test--) {

        string s; cin >> s;
        if(s[0] == '0') {cout << 0 << endl; continue;}

        // cout << s << endl;
        int lenS = s.size();

        s = "0" + s;
        vector<ll> dp(lenS + 1, 0); // dp[i]: lưu số cách giải mã chuỗi con gồm i ký tự đầu tiên
    
        // base case
        dp[0] = 1; // chuỗi rỗng có 1 cách giải mã
        dp[1] = 1; // luôn có 1 cách để giải mã ký tự đầu tiên
    
        for (int i = 2; i <= lenS; ++i) {
            if(s[i] != '0') dp[i] += dp[i - 1]; // cộng dồn với ký tự ngay trước
    
            // giải mã 2 chữ số -> nhìn lùi lại 2 bước
            int digits = (s[i - 1] - '0') * 10 + (s[i] - '0');
    
            // Hop le
            if(10 <= digits && digits <= 26) dp[i] += dp[i - 2];
        }
    
        cout << dp[lenS] << endl;
        
    }



    return 0;
}