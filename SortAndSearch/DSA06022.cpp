#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

signed main(){

    speed;  

    int test; cin >> test;
    int n;
    while(test--) {
        cin >> n;
        int a[n]; 
        int firstMin = LLONG_MAX, secondMin = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] < firstMin) {
                secondMin = firstMin;
                firstMin = a[i];
            }
            else if(a[i] < secondMin) {
                secondMin = a[i];
            }
        }
        
        if(firstMin == secondMin) {cout << -1 << endl; continue;}
        cout << firstMin << " " << secondMin << endl;
    }

    return 0;
}