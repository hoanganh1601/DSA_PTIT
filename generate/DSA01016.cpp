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
int a[12];

int cnt = 1;

void display() {
    cout << "(";
    for (int i = 1; i <= cnt; ++i) {
        cout << a[i];
        if(i != cnt) cout << " ";
    }
    cout << ") ";
}

void generate() {
    a[1] = n;
    display();
    while(1) {
        int i = cnt;
        while(i >= 1 && a[i] == 1) --i;
        if(i == 0) {
            cout << endl;
            return;
        }
        else {
            --a[i];
            int bu = cnt - i + 1;
            int thuong = bu / a[i];
            int du = bu % a[i];

            cnt = i;
            for (int j = 1; j <= thuong; ++j) {
                a[++cnt] = a[i]; 
            }

            if(du) a[++cnt] = du;

            display();
        }
    } 
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        generate();
        cnt = 1;
    }

    return 0;
}