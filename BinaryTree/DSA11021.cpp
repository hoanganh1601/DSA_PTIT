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

int pre[1005], n;

node *build(int left, int right) {
    if(left > right) return NULL;

    node *root = new node(pre[left]);
    int pos = left + 1;

    while(pos <= n && pre[pos] < pre[left]) ++pos;

    root->left = build(left + 1, pos - 1);
    root->right = build(pos, right);

    return root;
}

void leaf(node *root) {
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    leaf(root->left);
    leaf(root->right);
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test; cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> pre[i];
        }

        node *root = build(1, n);
        leaf(root);
        cout << endl;
    }

    return 0;
}