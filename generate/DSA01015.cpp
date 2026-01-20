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

signed main(){

    speed;  

    int test;
    cin >> test;

    while(test--) {
        cin >> n;
        queue<int> q;

        q.push(9);
        while(1) {
            int k = q.front();
            q.pop();
            if(k % n == 0) {
                cout << k << endl;
                break;
            }

            q.push(k * 10); // add 0
            q.push(k * 10 + 9); // add 9
        }
    }

    return 0;
}