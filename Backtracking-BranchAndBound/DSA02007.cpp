#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

string s, maxS;
int k;

// s: chuỗi hiện tại
// k: số lần đổi chỗ còn lại
// curIdx
void Try(string s, int k, int curIdx) {
    if(maxS < s) {
        maxS = s;
    }

    // hết chỗ đổi hoặc duyệt đến cuối
    if(k == 0 || curIdx == s.length()) return;

    // tìm ký tự lớn nhất trong phần còn lại từ curIdx + 1
    char maxChar = s[curIdx];
    for (int i = curIdx + 1; i < s.length(); ++i) {
        if(maxChar < s[i]) maxChar = s[i];
    }

    // maxChar nam o phan sau
    if(maxChar != s[curIdx]) {
        for (int i = curIdx + 1; i < s.length(); ++i) {
            // thu doi cho
            if(s[i] == maxChar) {
                swap(s[curIdx], s[i]);
                Try(s, k - 1, curIdx + 1);
                swap(s[i], s[curIdx]);
            }
        }
    }
    else {
        Try(s, k, curIdx + 1);
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> k;
        cin >> s;

        maxS = s;

        Try(s, k, 0);

        cout << maxS << endl;
    }

    return 0;
}