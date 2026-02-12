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
string tmp[12];
int res[12][12];
int listRes[12];
int ans = LLONG_MAX;

bool visited[12];

int cal(int i, int j) {
    string s = tmp[i], t = tmp[j];
    unordered_set<int> se;
    for (int i = 0; s[i]; ++i) se.insert(s[i]);
    for (int i = 0; t[i]; ++i) se.insert(t[i]);
    
    return s.size() + t.size() - se.size();
}

void init() {
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            res[i][j] = cal(i, j);
        }
    }
}

void Try(int i, int curVal) {
    
    if(curVal >= ans) return;

    if(i > n) {
        if(curVal < ans) ans = curVal;
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if(!visited[j]) {
            listRes[i] = j;
            if(curVal + res[listRes[i]][listRes[i - 1]] + res[listRes[i - 1]][listRes[i]] < ans) {
                visited[j] = 1;
                Try(i + 1, curVal + res[listRes[i]][listRes[i - 1]] + res[listRes[i - 1]][listRes[i]]);
                visited[j] = 0;
            }
        }
    }
}

signed main(){

    speed;  

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> tmp[i];
    
    init();
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) cout << res[i][j] << " ";
    //     cout << endl;
    // }

    Try(1, 0);

    cout << ans << endl;

    return 0;
}