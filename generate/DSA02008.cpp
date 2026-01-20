#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, k;
vector<vector<int>> listRes;
vector<int> res(12);

int a[12][12];
int curSum = 0;

int visited[12];

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if(!visited[j]) {
            if(curSum + a[i][j] > k) {continue;}
            res[i] = j;
            curSum += a[i][j];
            visited[j] = 1;

            if(i == n) {
                if(curSum == k) listRes.pb(vector<int>(res.begin() + 1, res.begin() + 1 + n));
            }
            else Try(i + 1);

            curSum -= a[i][j];
            visited[j] = 0;
        }
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }

    res.resize(n + 1);
    Try(1);

    cout << listRes.size() << endl;
    for (vector<int> x : listRes) {
        for (int y : x) cout << y << " ";
        cout << endl;
    }

    return 0;
}