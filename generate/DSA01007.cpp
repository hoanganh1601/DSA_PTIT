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
char x[12];
bool check = true;

void display() {
    for (int i = 1; i <= n; ++i) cout << x[i];
    cout << " ";
}

void generate() {
    int i = n;
    while(i >= 1 && x[i] == 'B') {
        x[i] = 'A';
        --i;
    }
    if(i == 0) check = false;
    else x[i] = 'B';
}

signed main(){

    speed;  

    int test; cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) x[i] = 'A';
        while(check) {
            display();
            generate();
        }
        cout << endl;

        check = true;
    }

    return 0;
}