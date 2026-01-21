#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

char c; 
int n, dis;
char a[40];

void display() {
    for (int i = 1; i <= n; ++i) cout << a[i];
    cout << endl;
}

void Try(int i, int start) {
    for (int j = start; j <= dis; ++j) {
        a[i] = 'A' + j;
        if(i == n) display();
        else Try(i + 1, j);
    }
}

signed main(){

    speed;  

    cin >> c >> n;
    dis = c - 'A';
    Try(1, 0);

    return 0;
}