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

    int test;
    cin >> test;
    int n, m;
    while(test--) {
        cin >> n >> m;
        int len = n + m;
        int x;
        multiset<int> se;
        for (int i = 0; i < len; ++i) {
            cin >> x;
            se.insert(x);
        }

        for (int x : se) cout << x << " ";
        cout << endl;
    }   

    return 0;
}