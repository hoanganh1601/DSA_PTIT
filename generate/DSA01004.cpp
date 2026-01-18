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
int x[17];
bool check = true;

void display() {
    for (int i = 1; i <= k; ++i) cout << x[i];
    cout << " ";
}

void generate() {
    int i = k;
    while(i >= 1 && x[i] == n - k + i) --i;
    if(i == 0) check = false;
    else {
        ++x[i];
        for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
    }
}

signed main(){

    speed;  

    int test; 
    cin >> test;   

    while(test--) {
        cin >> n >> k;
        for (int i = 1; i <= k; ++i) x[i] = i;

        while(check){
            display();
            generate();
        }
        cout << endl;

        check = true;
    }

    return 0;
}