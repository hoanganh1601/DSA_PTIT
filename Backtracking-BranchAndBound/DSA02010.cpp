#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, x;
int a[22];
vector<int> res;
bool check = false;
int cnt = 0;

void Try(int start, int curSum) {
    ++cnt;
    if(curSum == x) {
        check = true;
        cout << "[";
        int len = res.size();
        for (int i = 0; i < len; ++i) {
            cout << res[i];
            if(i != len - 1) cout << " ";
        }
        cout << "]";
        return;
    }

    for (int j = start; j <= n; ++j) {
        if(curSum + a[j] <= x) {
            res.pb(a[j]);
            Try(j, curSum + a[j]);
            res.pob();
        }
        // Không lựa chọn được số thỏa mãn từ i + 1 -> n --> cắt nhánh
        else break;
    }
}

signed main(){

    speed;  

    int test; 
    cin >> test;
    while(test--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);

        Try(1, 0);
        if(!check) cout << -1;
        cout << endl;
        check = false;
        cout << cnt << endl;
    }   

    return 0;
}