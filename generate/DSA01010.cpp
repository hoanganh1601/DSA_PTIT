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
int a[42];

void generate() {

    unordered_set<int> se;
    for (int i = 1; i <= k; ++i) se.insert(a[i]);

    int i = k;
    while(i >= 1 && a[i] == n - k + i) --i;
    if(i == 0) cout << k << endl;
    else {
        ++a[i];
        for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;

        for (int i = 1; i <= k; ++i) se.insert(a[i]);

        cout << se.size() - k << endl;
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i) cin >> a[i];

        generate();
    }

    return 0;
}