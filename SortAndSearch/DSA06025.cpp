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
    for (int i = 0; i < n; ++i) {
        
        int pos = i - 1, tmp = a[i];
        while(pos >= 0 && tmp < a[pos]) {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[++pos] = tmp;

        cout << "Buoc " << i << ": ";
        display(a, i + 1);
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