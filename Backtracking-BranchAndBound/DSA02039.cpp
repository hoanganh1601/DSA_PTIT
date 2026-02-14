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

vector<int> tmp;
vector<vector<int>> listRes;

void Try(int start, int curSum) {
    if(curSum == n) {
        listRes.pb(tmp);
        return;
    }

    for (int j = start; j <= n; ++j) {
        if(curSum + a[j] <= n) {
            tmp.pb(a[j]);
            Try(j, curSum + a[j]);
            tmp.pob();
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) a[i] = n - i + 1;
        Try(1, 0);
        cout << listRes.size() << endl;
        for (vector<int> x : listRes) {
            cout << "(";
            for (int i = 0; i < x.size(); ++i) {
                cout << x[i];
                if(i != x.size() - 1) cout << " ";
            }
            cout << ") ";
        }
        listRes.clear();
        if(test) cout << endl;
    }
    

    return 0;
}