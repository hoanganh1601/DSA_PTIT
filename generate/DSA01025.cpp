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
char x[18];

void display() {
    for (int i = 1; i <= k; ++i) cout << x[i];
    cout << endl;
}

void generate() {
    // first
    display();
    while(1) {
        int i = k;
        while(i >= 1 && x[i] == 'A' + n - k + i - 1) --i;
        if(i == 0) return;
        else {
            ++x[i];
            for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
            display();
        }
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i) {
            x[i] = 'A' + i - 1;
        }
        generate();
    }   

    return 0;
}