#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int row, col;
int a[505][505];

ll Area(vector<int> &h) {
    vector<ll> posPhai(col + 5, col + 1);
    stack<int> st1;

    for(int i = 1; i <= col; ++i) {
        if(st1.empty()) st1.push(i);
        else if(h[st1.top()] < h[i]) st1.push(i);
        else {
            while(!st1.empty() && h[st1.top()] > h[i]) {
                posPhai[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
    }

    vector<ll> posTrai(col + 5, 0);
    stack<int> st2;

    for(int i = col; i >= 1; --i) {
        if(st2.empty()) st2.push(i);
        else if(h[st2.top()] < h[i]) st2.push(i);
        else {
            while(!st2.empty() && h[st2.top()] > h[i]) {
                posTrai[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
    }

    ll res = -1;
    for (int i = 1; i <= col; ++i) {
        res = max(res, (posPhai[i] - posTrai[i] - 1) * h[i]);
    }
    return res;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> row >> col;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                cin >> a[i][j];
            }
        }

        ll res = 0;
        vector<int> h(col + 5, 0);
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if(a[i][j]) h[j] += 1;
                else h[j] = 0; 
            }

            res = max(res, Area(h));
        }

        cout << res << endl;
    }

    return 0;
}