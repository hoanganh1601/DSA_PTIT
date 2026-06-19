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

void postOrder(node *root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

node *build(int left, int right) {
    if(left > right) return NULL;
    
    node *tmp = new node(pre[left]);
    int idx = left + 1;
    while(idx <= n && pre[idx] < pre[left]) ++idx;

    tmp->left = build(left + 1, idx - 1);
    tmp->right = build(idx, right);

    return tmp;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while(test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> pre[i];
        }

        node *root = build(1, n);

        postOrder(root);
        cout << endl;
    }

    return 0;
}