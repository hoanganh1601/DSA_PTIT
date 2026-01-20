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
string res = "";

void display() {
    cout << res[0];
    for (int i = 1; i < n; ++i) {
        int x = (res[i] - '0') ^ (res[i - 1] - '0');
        cout << x;
    }
    cout << " ";
}

void generate() {
    display();
    while(1) {
        int i = res.size() - 1;
        while(i >= 0 && res[i] == '1') {
            res[i] = '0';
            --i;
        }
        if(i == -1) return;
        else res[i] = '1';

        display();
    }
}

signed main(){

    speed;  

    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 0; i < n; ++i) res += '0';
        generate();
        cout << endl;
        res.clear();
    }   

    return 0;
}