#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct node {
    int data;
    node *left, *right;

    node (int u) {
        data = u;
        left = NULL;
        right = NULL;
    }
};

int in[1000005];

node *build(int left, int right) {
    if(left > right) return NULL;

    int mid = (left + right) / 2;
    node *root = new node(in[mid]);

    root->left = build(left, mid - 1);
    root->right = build(mid + 1, right);

    return root;
}

int leaf(node *root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    return leaf(root->left) + leaf(root->right);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> in[i];
        }
        sort(in + 1, in + 1 + n);

        node *root = build(1, n);

        cout << leaf(root) << endl;
    }

    return 0;
}