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
        int x;
        set<int> sA, sB, uni;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            sA.insert(x);
            uni.insert(x);
        }
        for (int j = 0; j < m; ++j) {
            cin >> x;
            sB.insert(x);
            uni.insert(x);
        }

        for (int x : uni) cout << x << " ";
        cout << endl;
        for (int x : sA) {
            if(sB.find(x) != sB.end()) cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}