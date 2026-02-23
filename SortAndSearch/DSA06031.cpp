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
    int n, k;
    while(test--) {
        cin >> n >> k;
        // define Max - Heap
        // key: num, value: index
        priority_queue<pair<int, int>> pq;
        // Min - Heap: priority_queue<int, vector<int>, greater<int>>
        int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];

        for (int i = 0; i < k; ++i) pq.push({a[i], i});
        cout << pq.top().first << " ";

        for (int i = k; i < n; ++i) {

            pq.push({a[i], i});

            // Remove elements from the top if their index is outside the current window
            while(pq.top().second <= i - k) {
                pq.pop();
            }

            cout << pq.top().first << " ";
        } 
        cout << endl;
    }   

    return 0;
}