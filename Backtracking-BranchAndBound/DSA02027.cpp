#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

const int INF = 1e9;

int n; 
int arr[20][20];
int path[20];
int vs[20];
int cmin = INF;
int ans = INF;

void Try(int pos, int curCost) {
    if(pos == n) {
        ans = min(ans, curCost + arr[path[pos - 1]][1]);
        return;
    }

    for (int i = 2; i <= n; ++i) {
        if(!vs[i]) {
            if(curCost + (n - pos) * cmin < ans) {
                vs[i] = true;
                path[pos] = i;
                Try(pos + 1, curCost + arr[path[pos - 1]][i]);
            
                vs[i] = false;
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            if(i != j) {
                cmin = min(cmin, arr[i][j]);
            }
        }
    }

    memset(vs, false, sizeof(vs));
    path[0] = 1; 
    vs[1] = true;

    Try(1, 0);

    cout << ans << endl;
 
    return 0;
}