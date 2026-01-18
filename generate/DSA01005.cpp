#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int n, x[12];
bool check = true;

void display() {
    for (int i = 1; i <= n; ++i) cout << x[i];
    cout << " ";
}

void generate() {
    int i = n - 1;
    while(i >= 1 && x[i] > x[i + 1]) --i;
    if(i == 0) check = false;
    else {
        int j = n; 
        while(x[j] < x[i]) --j;
        
        swap(x[i], x[j]);

        int left = i + 1, right = n;
        while(left < right) {
            swap(x[left], x[right]);
            ++left; --right;
        }
    }
}

signed main(){

    speed;  

    int test; 
    cin >> test;

    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) x[i] = i;
        while(check) {
            display();
            generate();
        }
        cout << endl;
        check = true;
    }

    return 0;
}