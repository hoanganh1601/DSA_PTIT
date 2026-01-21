#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int ans = 0;
int n;
int res[12]; // idx: row. value = col
bool col[12], chinh[50], phu[50];

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if(!col[j] && !chinh[n - j + i] && !phu[i + j - 1]) {
            res[i] = j;
            col[j] = 1; chinh[n - j + i] = 1; phu[i + j - 1] = 1;
            
            if(i == n) ++ans;
            else Try(i + 1);

            col[j] = 0; chinh[n - j + i] = 0; phu[i + j - 1] = 0;
        }
    }
} 

signed main(){

    speed;  

    int test; 
    cin >> test;
    while(test--) {
        cin >> n;
        Try(1);
        cout << ans << endl;
        ans = 0;
    }   

    return 0;
}