#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

void init(int a[], int n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n1, n2, n3;
    while(test--) {
        cin >> n1 >> n2 >> n3;
        int a[n1], b[n2], c[n3];
        init(a, n1); init(b, n2); init(c, n3);  

        int i = 0, j = 0, k = 0;
        bool check = false;
        while(i < n1 && j < n2 && k < n3) {
            if(a[i] == b[j] && b[j] == c[k]) {
                check = true;
                cout << a[i] << " ";
                ++i; ++j; ++k;
            }
            else {
                int min_value = min({a[i], b[j], c[k]});
                if(a[i] == min_value) ++i;
                else if(b[j] == min_value) ++j;
                else ++k; 
            }
        }

        if(!check) cout << -1;
        cout << endl;
    }   

    return 0;
}