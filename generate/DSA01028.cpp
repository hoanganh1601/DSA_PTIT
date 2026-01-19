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
vector<int> res, a;

void display() {
    for (int i = 0; i < k; ++i) cout << res[a[i]] << " ";
    cout << endl;
}

void generate() {
    display();
    while(1) {
        int i = k - 1;
        while(i >= 0 && a[i] == n - k + i) --i;
        if(i == -1) return;
        else {
            ++a[i];
            for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
        }

        display();
    }
}

signed main(){

    speed;  

    cin >> n >> k;
    int x;
    set<int> se;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        se.insert(x);
    }

    res = vector<int>(se.begin(), se.end());
    n = res.size();
    a.reserve(k);
    for (int i = 0; i < k; ++i) a.pb(i);

    generate();

    return 0;
}   