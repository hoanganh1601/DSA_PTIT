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
vector<int> x;

void display() {
    for (int i = 1; i <= n; ++i) {
        if(x[i] == 1) cout << 'H';
        else cout << 'A';
    }
    cout << endl;
}

// 0: A, 1: H
void Try(int i) {

    for (int j = 0; j <= 1; ++j) {
        if(i == 1 && j == 0) continue;
        if(i == n && j == 1) continue;
        
        if(x[i - 1] == 1 && j == 1) continue;

        x[i] = j;
        if(i == n) {
            display();
        }
        else Try(i + 1);
    }
}

signed main(){

    speed;  

    int test; 
    cin >> test;

    x.reserve(18);
    while(test--) {
        cin >> n;
        Try(1);
    }   

    return 0;
}