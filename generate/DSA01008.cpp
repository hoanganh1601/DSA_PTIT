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
int a[18];
bool check = true;

void display() {
    for (int i = 1; i <= n; ++i) cout << a[i];
    cout << endl;
}

bool valid() {
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    return sum == k;
}

void generate() {
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if(i == 0) check = false;
    else a[i] = 1;
}

signed main(){

    speed;  

    int test; cin >> test;
    while(test--){
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) a[i] = 0;
        while(check) {
            if(valid()) display();
            generate();
        }

        check = true;
    }

    return 0;
}