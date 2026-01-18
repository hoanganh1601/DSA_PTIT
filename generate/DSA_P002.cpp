#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int a[12], n;
bool check = true;
int cnt = 1;

void init() {
    cin >> n;
    for (int i = 1; i <= n; ++i) a[i] = i;
}

void display() {
    cout << cnt << ": ";
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
}

void generate() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) --i;

    if(i == 0) check = false;
    else {
        int j = n;
        while(a[j] < a[i]) --j;
        
        swap(a[j], a[i]);

        int left = i + 1, right = n;
        while(left < right) {
            swap(a[left], a[right]);
            ++left; --right;
        }
    }
}

signed main(){

    speed;  

    init();
    while(check) {
        display();
        ++cnt;
        generate();
    }

    return 0;
}