#include <bits/stdc++.h>
#define int long long
#define speed ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define pob pop_back
#define endl "\n"
#define fi first 
#define se second

using namespace std;

int find(int n, int k) {
    // mid: 2 ^ (n - 1)
    int mid = (1LL << (n - 1));
    if(k == mid) return n;
    // search trong n - 1 thanh phan dang truoc
    else if(k < mid) return find(n - 1, k);
    else return find(n - 1, k - mid);
}

signed main(){

    speed;  

    int test;
    cin >> test;
    int n, k;
    while(test--) {
        cin >> n >> k;
        cout << find(n, k) << endl;
    }   

    return 0;
}