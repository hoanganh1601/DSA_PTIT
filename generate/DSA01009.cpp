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
string res = "";
vector<string> listRes;

bool check() {
    int cnt = 0;
    // first window
    int tmp = 0;
    for (int i = 0; i < k; ++i) {
        if(res[i] == 'A') ++tmp;
    }
    if(tmp == k) ++cnt;
    for (int i = k; i < n; ++i) {
        if(res[i - k] == 'A') --tmp;
        if(res[i] == 'A') ++tmp;

        if(tmp == k) ++cnt;
    }
    
    return cnt == 1; 
}

void generate() {

    if(check()) listRes.pb(res);

    while(1) {
        int i = n - 1;
        while(i >= 0 && res[i] == 'B') {
            res[i] = 'A';
            --i;
        }
        if(i == -1) return;
        else {
            res[i] = 'B';

            if(check()) listRes.pb(res);
        }
    }
}

signed main(){

    speed;  

    cin >> n >> k;   
    for (int i = 1; i <= n; ++i) res += 'A';
    listRes.reserve(100005);

    generate();

    cout << listRes.size() << endl;
    for (string x : listRes) cout << x << endl; 

    return 0;
}