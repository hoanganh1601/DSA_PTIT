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
int len;
vector<int> res;
bool check = true;

void init() {
    cin >> n;
    len = (n + 1) / 2;
    res.reserve(len + 1);
    res.pb(0);
    for (int i = 1; i <= len; ++i) {res.pb(0);}
}

void generate() {
    int i = len;
    while(i >= 1 && res[i] == 1) {
        res[i] = 0; 
        --i;
    }

    if(i == 0) check = false;
    else res[i] = 1;
}

void display() {
    for (int i = 1; i <= len; ++i) cout << res[i] << " ";

    int tmp = (len % 2 == 1) ? (len - 1) : len;

    for (int i = tmp; i >= 1; --i) cout << res[i] << " ";
    cout << endl; 
}

signed main(){

    speed;  

    init();

    while(check){
        display();
        generate();
    }

    return 0;
}