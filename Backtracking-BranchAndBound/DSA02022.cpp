#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int a[10];

void display() {
    
    for (int i = 1; i <= 8; ++i) {
        if(i == 3 || i == 5) cout << '/';
        if(a[i] == 1) cout << 2;
        else cout << a[i];
    }
    
    cout << endl;
}

void Try(int i) {
    for (int j = 0; j <= 1; ++j) {
        if(i == 2 && j == 0 && a[1] == 0) continue;
        if(i == 3 && j == 1) continue;
        if(i == 4 && j == 0) continue;
        if(i == 5 && j == 0) continue;

        a[i] = j;
        if(i == 8) display();
        else Try(i + 1);
    }
}

signed main(){

    speed;  

    Try(1);

    return 0;
}