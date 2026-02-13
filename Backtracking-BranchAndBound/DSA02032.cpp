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

vector<vector<int>> listRes;
vector<int> tmp;

void Try(int start, int curSum) {
    if(curSum == x) {
        listRes.pb(tmp);
        return;
    }

    for (int j = start; j <= n; ++j) {
        if(curSum + a[j] <= x) {
            tmp.pb(a[j]);
            Try(j, curSum + a[j]);
            tmp.pob();
        }
        else continue;
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

        if(listRes.empty()) {
            cout << -1;
        }
        else {
            cout << listRes.size() << " ";
            for (vector<int> x : listRes) {
                cout << "{";
                for (int i = 0; i < x.size(); ++i) {
                    cout << x[i];
                    if(i != x.size() - 1) cout << " ";
                }
                cout << "}" << " ";
            }
    
            listRes.clear();
        }
        
        if(test) cout << endl;
    }   

    return 0;
}