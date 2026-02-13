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
string listRes[10];
int pos[10];
int ans = LLONG_MAX;

bool visited[10];

// permutation of K 
void Try(int i) {
    for (int j = 1; j <= k; ++j) {
        if(!visited[j]) {
            pos[i] = j - 1;
            visited[j] = true;

            if(i == k) {
                int minVal = LLONG_MAX, maxVal = -1;
                for (int t = 1; t <= n; ++t) {
                    int curVal = 0;
                    for (int p = 1; p <= k; ++p) {
                        curVal = curVal * 10 + (listRes[t][pos[p]] - '0');
                    }
                    minVal = min(minVal, curVal);
                    maxVal = max(maxVal, curVal);
                }

                ans = min(ans, maxVal - minVal);
            }
            else Try(i + 1);

            visited[j] = false;
        }
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> listRes[i];

    Try(1);

    cout << ans << endl;

    return 0;
}