#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> b(a); sort(b.begin(), b.end());
        int first = b[0];
        
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if(first == a[i]) {
                pos = i;
                break;
            }
        }

        cout << pos << endl;
    }   

    return 0;
}