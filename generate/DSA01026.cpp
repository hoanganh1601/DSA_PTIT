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
int x[18];

void display() {
    for (int i = 1; i <= n; ++i) {
        if(x[i] == 1) cout << 8;
        else cout << 6;
    }
    cout << endl;
}

// 0: 6, 1: 8
void Try(int i) {
    for (int j = 0; j <= 1; ++j) {
        if(i == 1 && j == 0) continue;
        if(i == n && j == 1) continue;
        if(x[i - 1] == 1 && j == 1) continue;
        if(i >= 4 && x[i - 1] == 0 && x[i - 2] == 0 && x[i - 3] == 0 && j == 0) continue;

        x[i] = j;
        if(i == n) display();
        else Try(i + 1);
    }
}

signed main(){

    speed;  

    cin >> n;
    Try(1);

    return 0;
}