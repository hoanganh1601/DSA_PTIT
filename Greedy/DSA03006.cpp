#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

bool check(vector<int> a, int n) {
    vector<int> b = a;
    sort(b.begin(), b.end());

    int k = n / 2;
    bool check1, check2;
    for (int i = 0; i < k; ++i) {
        check1 = (a[i] == b[i] && a[n - i - 1] == b[n - i - 1]);
        check2 = (a[i] == b[n - i - 1] && b[i] == a[n - i - 1]);

        if(!check1 && !check2) return false;
    }

    // n is odd
    if(n % 2 == 1) {
        if(a[k] != b[k]) return false;
    }

    return true;
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n;
    while(test--) {
        cin >> n;
        vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
        if(check(a, n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }   

    return 0;
}