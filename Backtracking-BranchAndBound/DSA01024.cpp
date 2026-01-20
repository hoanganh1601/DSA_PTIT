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
string res[32], a[32];

void display() {

    for (int i = 1; i <= k; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int i, int start) {
    for (int j = start + 1; j <= n - k + i; ++j) {
        res[i] = a[j];

        if(i == k) display();
        else Try(i + 1, j);
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    string tmp;
    map<string, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        mp[tmp]++;
    }

    int idx = 1;
    for(pair<string, int> x : mp) {
        a[idx++] = x.fi;
    }

    n = mp.size(); 
    
    Try(1, 0);

    return 0;
}