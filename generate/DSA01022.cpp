#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n;
int a[12];

void generate() {
    int cnt = 0;
    bool check = true;

    while(check) {
        ++cnt;
        int i = n - 1;
        while(i >= 1 && a[i] < a[i + 1]) --i;
        if(i == 0) {
            check = false;
            cout << cnt << endl;
        }
        else {
            int j = n;
            while(a[j] > a[i]) --j;
            swap(a[j], a[i]);

            int left = i + 1, right = n;
            while(left < right) {
                swap(a[left], a[right]);
                ++left; --right;
            }
        }
    }
}

signed main(){

    speed;  

    int test; cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        generate();
    }   

    return 0;
}