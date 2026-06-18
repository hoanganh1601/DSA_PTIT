#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left;
    node *right;
    node (int u) {
        data = u;
        left = NULL;
        right = NULL;
    }
};

int n;
int in[1005];
int level[1005];
unordered_map<int, int> idx;

void postOrder(int left, int right) {
    if(left > right) return;
    
    int val = -1, rootPos = -1;

    for (int i = 1; i <= n; ++i) {
        int pos = idx[level[i]];
        if(pos >= left && pos <= right) {
            val = level[i];
            rootPos = pos;
            break;
        }
    }

    if(rootPos != -1) {
        postOrder(left, rootPos - 1);
        postOrder(rootPos + 1, right);

        cout << val << " ";
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> in[i];
            idx[in[i]] = i;
        }
        for (int i = 1; i <= n; ++i) cin >> level[i];

        postOrder(1, n);
        cout << endl;

        idx.clear();
    }

    return 0;
}