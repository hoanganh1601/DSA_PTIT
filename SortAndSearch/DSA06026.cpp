#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

void solve(int a[], int n) {
    bool ok;
    for (int i = 0; i < n - 1; ++i) {
        bool ok = false;
        for (int j = 1; j < n - i; ++j) {
            if(a[j - 1] > a[j]) {
                ok = true;
                swap(a[j - 1], a[j]);     
            }
        }

        if(!ok) break;

        cout << "Buoc " << i + 1 << ": ";
        display(a, n);
    }
}

signed main(){

    speed;  

    int n; 
    cin >> n;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
    
    solve(a, n);

    return 0;
}